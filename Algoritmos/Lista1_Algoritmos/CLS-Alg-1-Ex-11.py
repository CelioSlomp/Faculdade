from math import radians, acos, cos, sin

latitude1 = radians(float(input("Digite a latitude1: ")))
longitude1 = radians(float(input("Digite a longitude1: ")))

latitude2 = radians(float(input("Digite a latitude2: ")))
longitude2 = radians(float(input("Digite a longitude2: ")))

distancia = 6371.01 * acos(sin(latitude1)*sin(latitude2) + cos(latitude1)*cos(latitude2) * cos(longitude1-longitude2))

print(distancia)