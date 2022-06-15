soma = 3
print(soma)

j = 2
for i in range(0, 14):
    if i%2 == 1:
        multi = 1
        for s in range(j, j+3):
            multi *= s
        soma -= 4/multi
        j+=2
    else:
        multi = 1
        for s in range(j, j+3):
            multi *= s
        soma += 4/multi
        j+=2
    print(soma)