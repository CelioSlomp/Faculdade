OBJS = main.cpp src/glad.c

CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS = -Iinclude -lglfw -lGL -ldl

OBJ_NAME = main

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)