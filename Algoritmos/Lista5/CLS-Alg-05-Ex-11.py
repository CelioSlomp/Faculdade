from random import randint
def main():
    senha = ""
    for i in range(0, randint(7, 10)):
        senha += chr(randint(33, 126))
    return "A senha é: " + senha 


if __name__ == "__main__":
    print(main())