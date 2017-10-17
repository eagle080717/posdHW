#INC_DIR = include

all: utAtom utVariable hw3

utAtom: mainAtom.o
ifeq (${OS}, Windows_NT)
	g++ -o utAtom mainAtom.o -lgtest
else
	g++ -o utAtom mainAtom.o -lgtest -lpthread
endif

mainAtom.o: atom.h utAtom.h mainAtom.cpp
	g++ -std=gnu++0x -c mainAtom.cpp

utVariable: mainVariable.o
ifeq (${OS}, Windows_NT)
	g++ -o utVariable mainVariable.o -lgtest
else
	g++ -o utVariable mainVariable.o -lgtest -lpthread
endif

mainVariable.o: variable.h utVariable.h mainVariable.cpp
	g++ -std=gnu++0x -c mainVariable.cpp

hw3: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 main.o -lgtest
else
	g++ -o hw3 main.o -lgtest -lpthread
endif
main.o:	number.h utTerm.h utStruct.h main.cpp 
	g++ -std=gnu++0x -c main.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe utAtom utVariable hw3
else
	rm -f *.o utAtom utVariable hw3
endif