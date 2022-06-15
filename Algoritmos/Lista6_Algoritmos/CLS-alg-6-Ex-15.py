def main():
    tok = input("Digite uma formula: ")
    return token(tok)

def token(tok):
    tok = str(tok)
    tokens = []
    for i in range(0, len(tok)):
        
        
        if tok[i].isnumeric() and (tok[i-1] == "+" or tok[i-1] == "-"):
            tokens.append(tok[i-1] + tok[i])
        else:
            if tok[i] != " " and not tok[i+1].isnumeric():
                tokens.append(tok[i])
    return tokens


if __name__ == "__main__":
    print(main())