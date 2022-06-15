from operator import le
import string


x = input("Digite a string: ")

if len(x) %2 == 0:
    string1 = ""
    string2 = ""
    for i in range(0, int(len(x)/2)):
        string1 += x[i]
    for i in range(int((len(x)-1)), int((len(x)/2)-1), -1):
        string2 += x[i]
    if string1 == string2:
        print("São iguais")
    else:
        print("Não são iguais.")
else:
    string1 = ""
    string2 = ""
    for i in range(0, int(len(x)/2)):
        string1 += x[i]
    for i in range(int(len(x))-1, int(len(x)/2), -1):
        string2 += x[i]
    if string1 == string2:
        print("São iguais.")
    else:
        print("Não são iguais.")