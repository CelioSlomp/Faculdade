var = 0xf9
print(var)
numini = 100000
cont = 6
zerEsq = True

for i in range(0, 6):
    if var == 0 and cont == 0:
        break
    numini = numini // 10
    cont -= 1
    if numini <= var:
        zerEsq = False
        for j in range(1, 11):
            if numini * j > var:
                var -= numini * (j - 1)
                print(j - 1)
                break
    else:
        if not zerEsq:
            print(0)