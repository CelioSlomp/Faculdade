x1 = 1.8243
x2 = 1.8243

def f1(x1,x2):
    return (x1-1)**2 + x2**2-4

def f2(x1,x2):
    return x1**2+(x2-1)**2-4

def jacob(x1,x2):
    return [[2*(x1-1), 2*x2],
            [2*x1, 2*(x2-1)]]

print("f1:",f1(x1,x2))
print("f2:",f2(x1,x2))
jb = jacob(x1,x2)
print()
print("Jacobiano:")
print(jb[0])
print(jb[1])
print("-------------------")

s1 = (jb[0][0]/jb[0][1])
