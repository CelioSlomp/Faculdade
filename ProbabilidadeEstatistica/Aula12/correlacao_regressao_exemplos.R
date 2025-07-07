#----------------------------------------------------------------
# Correlação
#----------------------------------------------------------------

setwd("~/Jeovani_DELL_NOVO/1.AULAS_DISCIPLINAS_CONTEUDOS/AULAS_DISCIPLINAS_NO_IFC/PROBABILIDADE E ESTATÍSTICA 2025/Aula 16 - Correlacao e Regressao")
rm(list=ls(all=TRUE))
getwd()

# Exemplo 1 - pressão arterial x idade

# Dados
idade <- c(56, 42, 72, 36, 47, 55, 49, 38, 42, 68, 60, 63)
pressao <- c(147, 125, 160, 118, 128, 150, 145, 115, 140, 152, 155, 149)

#Gráfico
plot(idade, pressao)

# Gráfico pelo GGPLOT
library(ggplot2)
dados <- data.frame(idade, pressao)
ggplot(data = dados) + 
  geom_point(aes(x = idade, y = pressao)) 

# Coeficiente de correlação
cor(idade, pressao)

# Exemplo 2 - cerâmica

# leitura dos dados

# opção 1 - a partir do .csv
#library(data.table)
#dados <- fread(input = paste0("ceramica.csv"), 
#              header = T, na.strings = "NA", 
#              data.table = FALSE, dec=",")

#opão 2 - diretamente do RData
load("ceramica.RData")
dados <- ceramica

#Gráfico
plot(dados)

# Coeficiente de correlação
cor(dados)
correlacao <- cor(dados)

# Matriz do correlação
library(ggcorrplot)
ggcorrplot(correlacao)
ggcorrplot(correlacao, hc.order = TRUE, type = "lower",
           lab = TRUE)

# Exemplo 3 - salário
Experiencia <- c(1,2,3,4,5,5,8,10)
Salario <- c(3156,3248,3650,3689,3779,3907,3849,4118)
plot(Experiencia, Salario, lwd=8)

# Coeficiente de correlação
cor(Experiencia, Salario)

# Coeficientes do modelo
modelo <- lm(Salario ~ Experiencia)
modelo

# Reta de regressão no modelo
plot(Experiencia, Salario, lwd=8)
abline(lm(Salario ~ Experiencia))

# Coeficiente de determinação
summary(modelo)$r.squared

# Atenção! R2 pode ser alto e o ajuste não ser bom. Fazer a Análise de resíduos

# Análise de resíduos
plot(fitted(modelo), rstandard(modelo))
abline(0,0)



# Previsão
# Estime o salário para uma pessoa com 7 anos de empresa

predict(modelo,data.frame(Experiencia=7))

# ------------------------------

