import sys

if __name__ == "__main__":
    print(f"Número de argumentos: {len(sys.argv)}")
    for i, arg in enumerate(sys.argv):
        print(f"Argumento {i}: {arg}")