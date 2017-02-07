#INFORMÁTICA GRÁFICA
# GRADO EN INGENIERIA INFORMATICA
# GRUPO C1
# 
# LAURA TIRADO LOPEZ
# PRACTICA 1
#


BIN = ./bin
SRC = ./src
OBJ = ./obj
LIB = ./lib
INCLUDE = ./include

LDFLAGS= -lGL -lglut

all: clean $(BIN)/p1 
 
$(BIN)/p1 : $(OBJ)/escena.o $(OBJ)/practica1.o $(OBJ)/objeto3D.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o
	g++ -o $(BIN)/p1 $(OBJ)/escena.o $(OBJ)/practica1.o $(OBJ)/objeto3D.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(LDFLAGS)

$(OBJ)/escena.o : $(SRC)/escena.cpp $(INCLUDE)/escena.h 
	g++ -c -o $(OBJ)/escena.o $(SRC)/escena.cc -I$(INCLUDE)

$(OBJ)/cubo.o : $(SRC)/cubo.cpp  $(INCLUDE)/cubo.h
	g++ -c -o $(OBJ)/cubo.o $(SRC)/cubo.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/tetraedro.o : $(SRC)/tetraedro.cpp  $(INCLUDE)/tetraedro.h
	g++ -c -o $(OBJ)/tetraedro.o $(SRC)/tetraedro.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/objeto3D.o : $(SRC)/objeto3D.cpp  $(INCLUDE)/objeto3D.h
	g++ -c -o $(OBJ)/objeto3D.o $(SRC)/objeto3D.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/practica1.o : $(SRC)/practica1.cc
	g++ -c -o $(OBJ)/practica1.o $(SRC)/practica1.cc -I$(INCLUDE)

# LIMPEZA

clean : 
	-rm $(BIN)/* $(OBJ)/* 
 