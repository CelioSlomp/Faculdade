# Aula Introdução ao software R

# Comandos iniciais
rm(list=ls(all=TRUE)) # limpeza da área de trabalho
getwd()               # exibe a pasta atual 

# Definir a pasta de trabalho
setwd("C:/Users/jeova/OneDrive/Documentos/Jeovani_DELL_NOVO/1.AULAS_DISCIPLINAS_CONTEUDOS/AULAS_DISCIPLINAS_NO_IFC/PROBABILIDADE E ESTATÍSTICA 2025/Aula 3 - AED variaveis qualitativas/no R")

# R como calculadora

1+2+3
2+3*4
3/2+1
3**3
sqrt(2)
abs(-2*2)

# Operadores Lógicos
1 == 2
1 != 2
1 <= 2
1 < 2
1 > 2
1 >= 2

# Variáveis (Objetos)

x <- 2*3
x
x = 2*3
y <- sqrt(5)
z <- y+x
z
xsq = x**2 + y**2
xsq

# Estrutura de Dados

# Vetores
idade <- c(25, 32, 27, 33, 42, 21, 35, 45, 33, 25)
idade

# Fatores
sexo <- c("Masc", "Fem", "Fem", "Fem", "Masc", "Fem", "Masc", "Masc", "Fem", "Fem")
sexo

# Dataframe
df <- data.frame(idade, sexo)
df

lista <- list(idade, sexo, df)

# Estrutura de Dados - Criando um Data frame - Exemplo

ID_paciente <- c(1, 2, 3, 4) 
idade <- c(25, 34, 28, 52) 
peso <- c(70, 68.3, 90, 58.5) 
diabetes <- c("Tipo 1", "Tipo 2", "Tipo 1", "Tipo 1") 
status <- c("Ruim", "Bom", "Ótimo", "Ruim") 
dados <- data.frame(ID_paciente, idade, peso, diabetes, status) 
str(dados)
dados
save(dados, file= "dados_pacientes.RData")

#---------------------------------------------------------
rm(list=ls(all=TRUE))

# Leitura de uma base de dados
# Exemplo: BASE SALÁRIO DE FUNCIONÁRIOS QUE TRABALHAM COM DATA SCIENCE 
# salario.csv

# INSTALAR O PACOTE data.table
# install.packages("data.table")

# CARREGAR O PACOTE
library(data.table)

# LEITURA DA BASE
dir()
dados <- fread(input = "salarios.csv", header = T, na.strings = "NA", data.table = FALSE, dec=",")

# Verificação da leitura
class(dados)
dim(dados)
names(dados)
str(dados)
head(dados)
tail(dados)

sapply(dados, function(x)(sum(is.na(x)))) # contagem de dados faltantes

mean(dados$salario_USD)    # salário médio da população N = 607
sd(dados$salario_USD)      # desvio padrão

# CRIAR SUBCONJUNTO DE DADOS
dados1 <- dados[dados$ano==2020,]     # Seleciona os salários do ano de pagamento 2000
dados2 <- dados[dados$emprego=="FT",] # Seleciona os funcionários com contrato de tempo integral

# TAMANHO DA AMOSTRA
#install.packages("samplingbook")
library(samplingbook)
# o pacote samplingbook utiliza as fórmulas de tamanho de amostra apresentadas na aula 2

# tamanho da amostra para proporção
sample.size.prop(e=0.01, P = 0.5, N = Inf, level = 0.95)
sample.size.prop(e=0.01, P = 0.5, N = 607, level = 0.95)

# "e" = erro
#  equivale ao "d" das fórmulas apresentadas na aula 2

# tamanho da amostra para média
sample.size.mean(e=10000, S = 71000, N = 607, level = 0.95) 

# Extraindo uma amostra para estimar uma média no R
# AMOSTRA SIMPLES AO ACASO (ASA)
set.seed(1243)
asa147 <- dados[sample(nrow(dados), size=147),]
mean(asa147$salario_USD)   # salário médio da amostra n =147
mean(dados$salario_USD)    # salário médio da população N = 607

# intervalo de confiança
a = mean(asa147$salario_USD)
b = mean(dados$salario_USD)  
a
b
e = 10000 # erro definido pelo pesquisador

li = a - e # limite inferior do IC
ls = a + e # limite superior do IC
li
ls
b # verdadeiro salário médio

#--------------------------------------------
# Tabelas e Gráficos

# Construção de tabela para uma variável qualitativa

# carregando pacotes
rm(list=ls(all=TRUE))
library(data.table)
library(RcmdrMisc)  ## Para usar as funções do Rcmdr (ex. Recode)
library(dplyr)

# leitura da base
base <- fread(input = "salarios.csv", header = T, na.strings = "NA", data.table = FALSE, dec = ",") 

str(base$trab_remoto)
base$trab_remoto <- as.character(base$trab_remoto)
str(base$trab_remoto)

# Alterando a base de dados
# Recodifiar a variável trab_remoto com a função ifelse
base$trab_remoto <- ifelse(base$trab_remoto=="0","1:Não",ifelse(base$trab_remoto=="50","2:Parcial","3:Total"))
table(base$trab_remoto)

str(base$experiencia)
table(base$experiencia)

# Recodifiar a variável experiencia sem usar função

base$experiencia[base$experiencia == "EN"] = "1:EN"
base$experiencia[base$experiencia == "MI"] = "2:MI"
base$experiencia[base$experiencia == "SE"] = "3:SE"
base$experiencia[base$experiencia == "EX"] = "4:EX"

table(base$experiencia)

#------------------
write.csv2(base,"base_modif.csv", row.names=FALSE)
#------------------
save("base", file="base.RData")
#------------------
# TABELAS e GRÁFICOS

# UMA VARIAVEL QUALITATIVA
# Tabela para trabalho remoto

local({
  .Table <- with(base, table(trab_remoto))
  cat("\ncounts:\n")
  print(.Table)
  cat("\npercentages:\n")
  print(round(100*.Table/sum(.Table), 2))
})

# Gráfico para trabalho remoto

library(ggplot2) 
library(stringr)

format.args = list(decimal.mark = ",", big.mark = ".")
Freq = data.frame(table(base$trab_remoto)) 
Freq$Percentual=round(100*Freq[,2]/sum(Freq[,2]),1)  
names(Freq)=c("Resposta","Frequência","Porcentagem")
Graf1 = ggplot(Freq, aes(y = Porcentagem, x = Resposta, ymax=65)) +  # Ajustar ymax=65
  geom_bar(stat="identity", position="dodge", fill="bisque1") +
  geom_text(aes(label=scales::percent(Porcentagem/100, decimal.mark = ",", accuracy=0.1)),vjust=-1.0, hjust=0.2, 
            size=5.0,  position = position_dodge(0.9), angle=45, colour="white") + 
  xlab("") +
  theme_dark() +
  theme(legend.text = element_text(size=12),   axis.text=element_text(size=12), legend.position="bottom") +
  scale_y_continuous(breaks = c(0,10,20,30,40,50,60))  #Corrigido em função do tamanho das colunas
print(Graf1) 

# gráfico de setores (pizza) para variável trabalho remoto
pie(table(base$trab_remoto))             

# Gráfico para experiência

install.packages("vcd")
library(vcd)
counts <- table(base$experiencia)
counts
barplot(counts,
        main = "nível de experiência no cargo",
        xlab = "nível", ylab = "frequencia")

# DUAS VARIAVEIS QUALITATIVAS: 

## Tabela trabalho remoto por experiência

.Table <- xtabs(~experiencia+trab_remoto, data=base)
rowPercents(.Table)

# Gráfico com experiencia e trab_remoto
# Opção 1
freq.tabela <- table(base$experiencia,base$trab_remoto, useNA = "ifany") 
freq.tabela
porc.tabelaL <- round(prop.table(freq.tabela,1)*100,1)
porc.tabelaL
tabela <- data.frame(table(base$experiencia,base$trab_remoto))
colnames(tabela) <- c("Experiencia","Trab_Remoto","Freq")

ggplot(tabela, aes(fill=Trab_Remoto, y=Freq, x=Experiencia)) + 
  geom_bar(position="fill", stat="identity") +
  ylab("Porcentagem")

# Gráfico com experiencia e trab_remoto 
# opção 2
library(vcd)
counts <- table(base$experiencia, base$trab_remoto)
counts
barplot(counts,
        main = "Colunas agrupadas",
        xlab = "trabalho remoto", ylab = "frequência",
      col = c("red", "yellow","green","gray"),
      legend=rownames(counts), beside=TRUE)

# opção 3
counts <- table(base$trab_remoto,base$experiencia)
counts
barplot(counts,
        main = "Colunas agrupadas",
        xlab = "experiência", ylab = "frequência",
        col = c("red", "yellow","green"),
        legend=rownames(counts), beside=TRUE)


