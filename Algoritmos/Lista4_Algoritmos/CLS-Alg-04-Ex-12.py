print("    ", end="")
for i in range(1, 11):
    if i == 10:
        print(str(i) + "   ")
    else:
        print(str(i) + "   ", end="")

for i in range(1, 11):
    print(str(i)+ "   ", end="")
    for j in range(1, 11):
        if j*i < 10:
            if j == 10:
                print(str(j*i)+ "   ")
            else:    
                print(str(j*i)+ "   ", end="")
        else:
            if j == 10:
                print(str(j*i)+ "  ")
            else:    
                print(str(j*i)+ "  ", end="")