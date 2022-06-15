tempo = int(input("Digite o tempo em segundos: "))
dias = tempo//86400
tempo -= 86400*dias

horas = tempo//3600
tempo -= 3600*horas

minutos = tempo//60
tempo -= 60*minutos

print(f"O períoddo foi de {dias}:{horas:02d}:{minutos:02d}:{tempo:02d}")