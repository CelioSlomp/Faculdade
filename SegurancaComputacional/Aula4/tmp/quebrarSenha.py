from zipfile import ZipFile
import os

file_name = "teste/admincomp.zip"

x = 0
while x < 1001:

    with ZipFile(file_name, "r") as zip:

        senha = zip.namelist()[0].split(".")[0]

        zip.extractall(path="teste", pwd=senha.encode("utf-8"))
        os.remove(file_name)
        file_name = "teste/" + zip.namelist()[0]
    
    print(x)
    x += 1
    