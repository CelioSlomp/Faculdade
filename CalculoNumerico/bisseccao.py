from math import e, cos, sin, log

def f(x):
    return 3*log(x, e) - x*x/2

def main():
    a = 1
    b = 2
    erro = 0.5*10**(-6)
    cont = 0
    xk = (a+b)/2
    print(f"k={cont} | a={a:.10f} | b={b:.10f} | xk={xk:.10f} | f(a)={f(a):.2f} | f(b)={f(b):.2f} | |b-a|={abs(b-a)}")
    while abs(b-a) > erro:

        if (f(a)*f(xk) > 0):
            a = xk
        else:
            b = xk

        xk = (a+b)/2
        cont+=1
        print(f"k={cont} | a={a:.10f} | b={b:.10f} | xk={xk:.10f} | f(a)={f(a):.2f} | f(b)={f(b):.2f} | |b-a|={abs(b-a)}")




if __name__ == "__main__":
    main()
