from zipfile import ZipFile 

file_name = "admincomp.zip"

with ZipFile(file_name, "r") as zip:
    senha = ""
    zip.extractall(path="uncompressed", pwd="".encode("utf-8"))
    