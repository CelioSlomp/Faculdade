# Arquivos a serem compilados
OBJS = main.cpp src/glad.c src/imagem.cpp

# Compilador
CC = g++

COMPILER_FLAGS = -w

# flags por causa do glad, opengl, etc.
LINKER_FLAGS = -Iinclude -lglfw -lGL -ldl

# Arquivo de saida
OBJ_NAME = main

# Comando para compilar
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)