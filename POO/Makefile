#OBJS specifies which files to compile as part of the project
arqComp = main.cpp

#CC specifies which compiler we're using
compilador = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
arqSaida = main

#This is the target that compiles our executable
all : $(arqComp)
	$(compilador) -c rendertela.cpp $(COMPILER_FLAGS)
	$(compilador) -c matematica.cpp $(COMPILER_FLAGS)
	$(compilador) -c vetor.cpp $(COMPILER_FLAGS)
	$(compilador) -c circulo.cpp $(COMPILER_FLAGS)
	$(compilador) -c figgeo.cpp $(COMPILER_FLAGS)
	$(compilador) $(arqComp) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(arqSaida)

clean:
	rm -f *.o
	@echo Tudo limpo e compilado!