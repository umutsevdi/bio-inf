SHELL := /bin/bash
PROG= bin/build
LIB= $(wildcard inc/*.h*)
SRC= $(wildcard src/*.c*)
OBJ= $(wildcard obj/*.o)
compile: $(SRC) $(LIB)
	g++ -c $(SRC) $(LIB) 
	mv *.o obj
build: $(OBJ)
	g++ -o $(PROG) $(OBJ)
clean:
	rm $(PROG) $(OBJ) 2> /dev/null
