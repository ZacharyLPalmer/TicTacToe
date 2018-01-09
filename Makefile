CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic
LSFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJ = TTT.o

all: TTT

TTT: TTT.o
	$(CXX) TTT.o -o ticTacToe $(LSFMLFLAGS)

TTT.o: TTT.cpp TTT.hpp
	$(CXX) -c TTT.cpp $(CXXFLAGS)


clean:
	rm ticTacToe $(OBJ) *~ *.gch -rf
