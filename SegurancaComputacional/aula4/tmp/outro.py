from zipfile import ZipFile
import threading

file_name = "teste/HackerSec.zip"
def thre(x1,x2,x3):

    for x4 in txt:
        for x5 in txt:
            for x6 in txt:
                with ZipFile(file_name, "r") as zip:
                    senha = x1+x2+x3+x4+x5+x6
                    try:       
                        zip.extractall(path="teste", pwd=senha.encode("utf-8"))
                        exit()
                    except:
                        pass

txt = 'abcdefghijklmnopqrstuvwxyz'
for x1 in txt:
    print("mudou o x1", x1)
    print("-------------------------------")
    for x2 in txt:
        for x3 in txt:
            x = threading.Thread(target=thre, args=(x1,x2,x3))
            x.start()
            