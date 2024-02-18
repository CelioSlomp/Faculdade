def main():
    palavra = input("Digite a palavra que desejas codificar: ")
    return codMorse(palavra)

def codMorse(pal:str):
    cod = {
        "A": ".-", "J": ".---", "K": "-.-", "T": "-", "U": "..-", "3": "...--",
        "B": "-...", "I": "..", "L": ".-..", "S": "...", "V": "...-", "2": "..---",
        "C": "-.-.", "H": "....", "M": "--", "R": ".-.", "W": ".--", "1": ".----",
        "D": "-..", "G": "--.", "N": "-.", "Q": "--.-", "X": "-..-", "0": "-----",
        "E": ".", "F": "..-.", "O": "---", "P": ".--.", "Y": "-.--", "Z": "--..",
        "4": "....-", "7": "--...", "8": "---..", "5": ".....", "6": "-....", 
        "9": "----."
    }
    palavraCod = ""
    for i in pal.upper():
        if i in cod:
            palavraCod += cod[i] + " "
    palavraCod.removesuffix(" ")
    return palavraCod





if __name__ == "__main__":
    print(main())