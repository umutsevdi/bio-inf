SHELL := /bin/bash
CXXFLAGS = -Wall -Werror -std=c++11

# Files
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp,obj/%.o,$(SRC))
INC = $(wildcard inc/*.h*)
BIN = bin/build

# Targets
all: $(BIN)

# Parameters:
# Depending on the example the compilation changes. - default 1
EXAMPLE ?= 1

$(BIN): $(OBJ)
	g++ $(CXXFLAGS) $(OBJ) -o $(BIN)

obj/%.o: src/%.cpp
# Replace the letter for the example
	@sed -i "s/#define EXAMPLE_./#define EXAMPLE_$(EXAMPLE)/" src/main.cpp
	g++ $(CXXFLAGS) -c $< -o $@  -Iinc

clean:
	@sed -i "s/#define EXAMPLE_./#define EXAMPLE_1/" src/main.cpp
	rm -f $(OBJ) $(BIN)

# Example:
# make EXAMPLE=2
