# Questão 1
# Questão 1
# Questão 1

# letra a

freq.tabela <- table(seguro$sinistro) # frequencia absoluta
freq.tabela

relativa <- prop.table(freq.tabela) # frequencia relativa
relativa

# letra b
install.packages("ggplot2")
library(ggplot2)
freq_instrucao <- as.data.frame(table(seguro$instrucao))
colnames(freq_instrucao) <- c("Ensino", "Frequencia")

ggplot(freq_instrucao, aes(x = Ensino, y = Frequencia)) +
  geom_bar(stat = "identity", fill = "blue")

# letra c
cruzada <- table(seguro$estado, seguro$sinistro)
cruzada

# letra d
ggplot(seguro, aes(x = instrucao, fill = sinistro)) +
  geom_bar(position = "stack")

# letra e
hist(seguro$renda,
     main="Histograma de renda",
     xlab="Renda",
     ylab = "Frequencia",
     col="darkmagenta",
     freq=TRUE)

boxplot(seguro$renda, main="Boxplot renda")

iqr <- IQR(seguro$renda)
q1 <- quantile(seguro$renda, 0.25)
q3 <- quantile(seguro$renda, 0.75)

inf <- q1 - 1.5 * iqr
sup <- q3 + 1.5 * iqr


outliers <- seguro$renda[seguro$renda < inf | seguro$renda > sup]
outliers


install.packages("e1071")
library("e1071")
skewness(seguro$renda)

# letra f
renda <- seguro$renda
mean(renda)     # média
median(renda)   # mediana
sd(renda)       # desvio padrão
coefvari <- (sd(renda)/mean(renda))*100     # coeficiente variacao
quantile(seguro$renda, probs=c(0.25,0.75)) # quartis

# letra g
renda <- seguro$renda
faixas <- cut(
  renda,
  breaks = c(0, 1.9, 3.9, 6.9, Inf),
  labels = c("Até 1.9", "2.0 até 3.9", "4.0 até 6.9", "7.0 ou mais")
)

tabelafaixas <- table(faixas)
frequencia <- prop.table(tabelafaixas) * 100

tabela <- data.frame(
  faixas = names(tabelafaixas),
  frequencias = as.vector(tabelafaixas),
  frqrelativa = round(as.vector(frequencia), 2)
)
tabela

# letra h
renda <- seguro$renda
ensino <- seguro$instrucao

boxplot(renda ~ ensino,
        main = "Boxplot da Renda por Ensino",
        xlab = "Ensino",
        ylab = "Renda",
        las = 2)

# letra i
renda <- seguro$renda
instrucao <- seguro$instrucao

ensino <- c("fundamental", "médio", "superior")

for (i in ensino) {
  print(i)
  
  dados <- renda[instrucao == i]
  
  media <- mean(dados, na.rm = TRUE) #media
  mediana <- median(dados, na.rm = TRUE)  #mediana
  q1 <- quantile(dados, 0.25, na.rm = TRUE)#q1
  q3 <- quantile(dados, 0.75, na.rm = TRUE)#q3
  desvio <- sd(dados, na.rm = TRUE)#desvio
  cv <- (desvio / media) * 100#cv
  
  print(paste("media:", media))
  print(paste("mediana:", mediana))
  print(paste("q1:", q1))
  print(paste("q3:", q3))
  print(paste("desvio padrao:", desvio))
  print(paste("coeficiente de variacao (%):", cv))
  
  print("------------------")
}

# questão 2
# questão 2
# questão 2

# Considerando N = 110
N = 110

# z = 1,96; d = 6 e o = 14
z = 1.96
d = 6
o = 14

n0 = ((z^2)*(o^2))/(d^2)

n = n0/(1 + n0/N)
n

# questão 3
# questão 3
# questão 3

# media amostral
idades = seguro$idade

idadessorteadas <- sample(idades, size=18, replace=FALSE)
idadessorteadas
erro <- 6

media <- mean(idadessorteadas)
inf <- media - erro
sup <- media + erro

print(paste("media:", media))
print(paste("erro inferior:", inf))
print(paste("erro superior:", sup))

#media geral
idades = seguro$idade

erro <- 6

media <- mean(idades)
inf <- media - erro
sup <- media + erro

print(paste("media:", media))
print(paste("erro inferior:", inf))
print(paste("erro superior:", sup))