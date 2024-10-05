from math import e, cos, sin, log, pi

def f(x):
    return 2*cos(x) - (e**x)/2

def main():
    a = 0
    b = 1
    erro = 1/10
    cont = 0
    xk = (a+b)/2
    print(f"k={cont} | a={a:.10f} | b={b:.10f} | xk={xk:.10f} | f(a)={f(a):.2f} | f(xk)={f(xk):.2f} | |b-a|={abs(b-a)}")
    while abs(b-a) > erro:

        if (f(a)*f(xk) > 0):
            a = xk
        else:
            b = xk

        xk = (a+b)/2
        cont+=1
        print(f"k={cont} | a={a:.10f} | b={b:.10f} | xk={xk:.10f} | f(a)={f(a):.2f} | f(xk)={f(xk):.2f} | |b-a|={abs(b-a)}")




if __name__ == "__main__":
    main()
