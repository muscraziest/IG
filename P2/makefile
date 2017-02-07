#INFORMÁTICA GRÁFICA
# GRADO EN INGENIERIA INFORMATICA
# GRUPO C1
# 
# LAURA TIRADO LOPEZ
# PRACTICA 2
#

BIN = ./bin
SRC = ./src
OBJ = ./obj
INCLUDE = ./include

LDFLAGS= -lGL -lglut

 
$(BIN)/p2 : $(OBJ)/escena.o $(OBJ)/practica2.o $(OBJ)/objeto3D.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(OBJ)/ply.o $(OBJ)/file_ply_stl.o $(OBJ)/or.o
	g++ -o $(BIN)/p2 $(OBJ)/escena.o $(OBJ)/practica2.o $(OBJ)/objeto3D.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(OBJ)/ply.o $(OBJ)/file_ply_stl.o $(OBJ)/or.o $(LDFLAGS) -std=c++11

$(OBJ)/escena.o : $(SRC)/escena.cc $(INCLUDE)/escena.h 
	g++ -c -o $(OBJ)/escena.o $(SRC)/escena.cc -I$(INCLUDE) 

$(OBJ)/cubo.o : $(SRC)/cubo.cpp  $(INCLUDE)/cubo.h
	g++ -c -o $(OBJ)/cubo.o $(SRC)/cubo.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/tetraedro.o : $(SRC)/tetraedro.cpp  $(INCLUDE)/tetraedro.h
	g++ -c -o $(OBJ)/tetraedro.o $(SRC)/tetraedro.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/ply.o : $(OBJ)/file_ply_stl.o $(SRC)/ply.cpp $(INCLUDE)/ply.h $(INCLUDE)/file_ply_stl.h
	g++ -c -o $(OBJ)/ply.o $(OBJ)/file_ply_stl.o $(SRC)/ply.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/or.o : $(SRC)/or.cpp $(INCLUDE)/or.h 
	g++ -c -o $(OBJ)/or.o $(SRC)/or.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/file_ply_stl.o : $(SRC)/file_ply_stl.cc $(INCLUDE)/file_ply_stl.h
	g++ -c -o $(OBJ)/file_ply_stl.o $(SRC)/file_ply_stl.cc -I$(INCLUDE) 

$(OBJ)/objeto3D.o : $(SRC)/objeto3D.cpp  $(INCLUDE)/objeto3D.h
	g++ -c -o $(OBJ)/objeto3D.o $(SRC)/objeto3D.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/practica2.o : $(SRC)/practica2.cc
	g++ -c -o $(OBJ)/practica2.o $(SRC)/practica2.cc -I$(INCLUDE)  

# LIMPEZA

clean : 
	-rm *.o  
 
