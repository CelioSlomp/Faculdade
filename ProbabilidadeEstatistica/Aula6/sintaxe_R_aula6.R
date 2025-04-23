# Aula 6 - Box Plot e Medidas resumo
# Comandos iniciais
rm(list=ls(all=TRUE)) # limpeza da área de trabalho
getwd()               # exibe a pasta atual 

# Definir a pasta de trabalho
setwd("C:/Users/jeova/OneDrive/Documentos/Jeovani_DELL_NOVO/1.AULAS_DISCIPLINAS_CONTEUDOS/AULAS_DISCIPLINAS_NO_IFC/PROBABILIDADE E ESTATÍSTICA 2025/Aula 6 - Box Plot")


# CARREGAR O PACOTE
library(data.table)

# Exemplo 1: Notas da P1 de 40 alunos da TURMA A

TURMA_A <- c(0,rep(10,2),20,30,rep(40,4),rep(50,5),rep(60,4),rep(70,6),rep(80,8),rep(90,4),rep(100,4))
TURMA_A

summary(TURMA_A)
sd(TURMA_A)
cv_TURMA_A <- (sd(TURMA_A)/mean(TURMA_A))*100
cv_TURMA_A
IQR(TURMA_A)
quantile(TURMA_A, probs=c(0.25,0.50,0.75))
quantile(TURMA_A, seq(0,1,0.10), na.rm=TRUE)

# histograma das notas
hist(TURMA_A, nclass = 5)
hist(TURMA_A, ylab="número de alunos", main="Notas dos alunos da TURMA A")
hist(TURMA_A, scale="frequency", breaks="Sturges", col="blue", xlab="notas", 
     ylab="número de alunos", main="Notas da Turma A")

# box plot para as notas dos 40 alunos
boxplot(TURMA_A, horizontal = F, main = "Notas da Turma A")   

# Para obter mais estatísticas descritivas usar
# a função basicStats do pacote fBasics

library(fBasics) 
basicStats(TURMA_A)  
#install.packages("fBasics") 
#---------------------------------------------------------

# Exemplo 2: Notas da P1 de 70 alunos da TURMA B

TURMA_B <- c(rep(5,9),8,rep(10,5),rep(15,2),rep(20,7),rep(25,5),rep(30,3),rep(35,7),rep(40,5),rep(45,4),rep(50,6),rep(55,3),rep(60,2),rep(70,2),80,85,rep(90,2),95,rep(100,4))
TURMA_B

# aqui em diante você deve se basear na sintaxe do exemplo 1


#---------------------------------------------------------
# Exemplo 3

# LEITURA DA BASE
dir()
dados <- fread(input = "notas.csv", header = T, na.strings = "NA", data.table = FALSE, dec=",")

# Verificação da leitura
class(dados)
dim(dados)
names(dados)
str(dados)
head(dados)
tail(dados)

# box plot das notas por turma
boxplot(dados$nota~dados$turma)

sapply(dados, function(x)(sum(is.na(x)))) # contagem de dados faltantes

# Histograma das notas por turma

require(lattice)
#install.packages("lattice")
histogram(~nota|factor(turma), data=dados)

