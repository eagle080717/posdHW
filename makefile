#INC_DIR = include

all: utAtom hw3

utAtom: mainAtom.o
ifeq (${OS}, Windows_NT)
	g++ -o utAtom mainAtom.o -lgtest
else
	g++ -o utAtom mainAtom.o -lgtest -lpthread
endif

mainAtom.o: atom.h utAtom.h mainAtom.cpp
	g++ -std=gnu++0x -c mainAtom.cpp

hw3: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 main.o -lgtest
else
	g++ -o hw3 main.o -lgtest -lpthread
endif

main.o:	main.cpp number.h struct.h utStruct.h variable.h utVariable.h
	g++ -std=gnu++0x -c main.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe utAtom hw3
else
	rm -f *.o utAtom hw3
endif