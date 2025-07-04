setwd("C:/Users/jeova/OneDrive/Documentos/Jeovani_DELL_NOVO/1.AULAS_DISCIPLINAS_CONTEUDOS/AULAS_DISCIPLINAS_NO_IFC/PROBABILIDADE E ESTATÍSTICA 2025/Aula 15 - Estimacao")
rm(list=ls(all=TRUE))
getwd()

load("dados.RData")
#View(dados)
names(dados)
mean(dados$salario_USD)
sd(dados$salario_USD)
summary(dados$salario_USD)
options(scipen = 999)

hist(dados$salario_USD, col='steelblue', main='Histograma do Salário',xlim=c(1000,700000))


# AMOSTRA SIMPLES AO ACASO (n=10)
asa10 <- dados[sample(nrow(dados), size=10), ]
mean(asa10$salario_USD)

# AMOSTRA SIMPLES AO ACASO (n=100)
asa100 <- dados[sample(nrow(dados), size=100), ]
mean(asa100$salario_USD)

# TEOREMA CENTRAL DO LIMITE
# Retirar 1000 vezes uma amostra de tamanho 30
amostra30 <- c()
n = 1000
for (i in 1:n){
  amostra30[i] = mean(sample(dados$salario_USD, 30, replace=TRUE))
}
hist(amostra30, col='steelblue', main='Histograma das médias das amostras n=30',xlim=c(1000,700000))

# -----------------------------------------------------
# Exercício
# TIRANDO UMA AMOSTRA DE TAMANHO 100
Amostra100 <- sample(dados$salario_USD, 100, replace=TRUE)
mean(Amostra100)
sd(Amostra100)

# INTERVALO DE CONFIANÇA 95%
media=mean(Amostra100)  # média da amostra de tamanho 100
n=length(Amostra100)
n
desvio_P=sd(dados$salario_USD)
IC=0.95
IC_LI=media-qnorm(IC+(1-IC)/2)*desvio_P/sqrt(n)
IC_LS=media+qnorm(IC+(1-IC)/2)*desvio_P/sqrt(n)

# Resultados da amostra de tamanho 100
n
IC
round(media,0)
round(desvio_P,0)
round(IC_LI,0);round(IC_LS,0)
media

