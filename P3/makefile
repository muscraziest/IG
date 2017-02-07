#INFORMÁTICA GRÁFICA
# GRADO EN INGENIERIA INFORMATICA
# GRUPO C1
# 
# LAURA TIRADO LOPEZ
# PRACTICA 3
#

BIN = ./bin
SRC = ./src
OBJ = ./obj
INCLUDE = ./include

LDFLAGS= -lGL -lglut

 
$(BIN)/p3 : $(OBJ)/escena.o $(OBJ)/practica3.o $(OBJ)/objeto3D.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(OBJ)/ply.o $(OBJ)/file_ply_stl.o $(OBJ)/or.o $(OBJ)/sonic.o $(OBJ)/pierna.o $(OBJ)/brazo.o $(OBJ)/torso.o
	g++ -o $(BIN)/p3 $(OBJ)/escena.o $(OBJ)/practica3.o $(OBJ)/objeto3D.o $(OBJ)/cubo.o $(OBJ)/tetraedro.o $(OBJ)/ply.o $(OBJ)/file_ply_stl.o $(OBJ)/or.o $(OBJ)/sonic.o $(OBJ)/pierna.o $(OBJ)/brazo.o $(OBJ)/torso.o $(LDFLAGS) -std=c++11

$(OBJ)/escena.o : $(SRC)/escena.cc $(INCLUDE)/escena.h 
	g++ -c -o $(OBJ)/escena.o $(SRC)/escena.cc -I$(INCLUDE) 

$(OBJ)/cubo.o : $(SRC)/cubo.cpp  $(INCLUDE)/cubo.h
	g++ -c -o $(OBJ)/cubo.o $(SRC)/cubo.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/tetraedro.o : $(SRC)/tetraedro.cpp  $(INCLUDE)/tetraedro.h
	g++ -c -o $(OBJ)/tetraedro.o $(SRC)/tetraedro.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/ply.o : $(OBJ)/file_ply_stl.o $(SRC)/ply.cpp $(INCLUDE)/ply.h $(INCLUDE)/file_ply_stl.hpp
	g++ -c -o $(OBJ)/ply.o $(OBJ)/file_ply_stl.o $(SRC)/ply.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/or.o : $(SRC)/or.cpp $(INCLUDE)/or.h 
	g++ -c -o $(OBJ)/or.o $(SRC)/or.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/file_ply_stl.o : $(SRC)/file_ply_stl.cc $(INCLUDE)/file_ply_stl.hpp
	g++ -c -o $(OBJ)/file_ply_stl.o $(SRC)/file_ply_stl.cc -I$(INCLUDE) 

$(OBJ)/sonic.o: $(SRC)/sonic.cpp $(INCLUDE)/sonic.h 
	g++ -c -o $(OBJ)/sonic.o $(SRC)/sonic.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/brazo.o : $(SRC)/brazo.cpp $(INCLUDE)/brazo.h
	g++ -c -o $(OBJ)/brazo.o $(SRC)/brazo.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/torso.o : $(SRC)/torso.cpp $(INCLUDE)/torso.h
	g++ -c -o $(OBJ)/torso.o $(SRC)/torso.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/pierna.o : $(SRC)/pierna.cpp $(INCLUDE)/pierna.h
	g++ -c -o $(OBJ)/pierna.o $(SRC)/pierna.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/objeto3D.o : $(SRC)/objeto3D.cpp  $(INCLUDE)/objeto3D.h
	g++ -c -o $(OBJ)/objeto3D.o $(SRC)/objeto3D.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/practica3.o : $(SRC)/practica3.cc
	g++ -c -o $(OBJ)/practica3.o $(SRC)/practica3.cc -I$(INCLUDE)  

# LIMPEZA

clean : 
	-rm *.o  
 
