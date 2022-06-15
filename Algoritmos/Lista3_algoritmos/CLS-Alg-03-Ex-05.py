mes = input("Digite o nome do mes: ")
mes = mes.lower()
if mes == "fevereiro":
    print("28 ou 29 dias")
elif mes == "janeiro" or mes == "março" or mes == "maio" \
    or mes == "maio" or mes == "julho" or mes == "agosto" \
    or mes == "outubro" or mes == "dezembro":
    print("o mes tem 31 dias")
else:
    print("o mes tem 30 dias")