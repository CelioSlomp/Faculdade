# Aula 5 - Medidas resumo
# Comandos iniciais
rm(list=ls(all=TRUE)) # limpeza da área de trabalho
getwd()               # exibe a pasta atual 

# Definir a pasta de trabalho
setwd("C:/Users/jeova/OneDrive/Documentos/Jeovani_DELL_NOVO/1.AULAS_DISCIPLINAS_CONTEUDOS/AULAS_DISCIPLINAS_NO_IFC/PROBABILIDADE E ESTATÍSTICA 2025/Aula 5 - Medidas resumo")


# CARREGAR O PACOTE
library(data.table)

# Exemplo 1
faltas <- c(0,2,3,1,0,1,2,2,3,1,2,3,2,1) # Criar o vetor com os dados
mean(faltas)

faltas <- c(rep(0,2),rep(1,4),rep(2,5),rep(3,3))
mean(faltas)

# Exemplo 2
faltas <- c(rep(0,2),rep(1,3),rep(2,5),rep(3,3),25)
mean(faltas)

# Exemplo 3
freq <- c(16,  8,  2)
peso <- freq/sum(freq)
x <- c(15,16,17)
xp <- weighted.mean(x, peso)
xp

# Exemplo 4
turismo <- c(40,52,48,54,60,58,45,54,42)
median(turismo)

# Exemplo 5
dados <- c(15,18,5,7,9,11,3,5,6,8,12) 
dados
quantile(dados, probs=c(0.25,0.50,0.75))

# Exemplos 6, 7 e 8

mA <- c(200,210,190,215,185)
mB <- c(152,248,260,200,140)
mC <- c(205,203,195,197,200)

sd(mA)
sd(mB)
sd(mC)

cv_mA <- (sd(mA)/mean(mA))*100
cv_mB <- (sd(mB)/mean(mB))*100
cv_mC <- (sd(mC)/mean(mC))*100

round(cv_mA, digits = 2)
round(cv_mB, digits = 2)
round(cv_mC, digits = 2)


# Exercício final
notas <- c(0,rep(10,2),20,30,rep(40,4),rep(50,5),rep(60,4),rep(70,6),rep(80,8),rep(90,4),rep(100,4))

notas

mean(notas)                                                   # calcula a média
quantile(notas, probs=c(0.25,0.50,0.75))     # Calcula Qi, Md, QS
quantile(notas,.95)                                         # Calcule o percentil 95
sd(notas)                                                        # desvio padrão
cv_notas <- (sd(notas)/mean(notas))*100     # coeficiente de variação
cv_notas

hist(notas, ylab="número de alunos", main="Notas dos alunos")
hist(notas, scale="frequency", breaks="Sturges", col="blue", xlab="notas", 
     ylab="número de alunos", main="Notas dos alunos")

#-------------------------------------------------------------
