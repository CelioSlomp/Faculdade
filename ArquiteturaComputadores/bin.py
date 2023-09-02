var = 40006
print(var)
numini = 10000
zeroEsq = True

while var != 0:
    if not zeroEsq or var > numini:
        print(int(var//numini), end='')
        var = var%numini
        zeroEsq = False
    numini /= 10