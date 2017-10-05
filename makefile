<<<<<<< HEAD

#INC_DIR = include

all: utAtom utVariable hw2

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


hw2: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 main.o -lgtest
else
	g++ -o hw2 main.o -lgtest -lpthread
endif
main.o:	number.h utTerm.h main.cpp 
	g++ -std=gnu++0x -c main.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe utAtom utVariable hw2
else
	rm -f *.o utAtom utVariable hw2
=======
INC_DIR = include

all: hw1

hw1: main.o Shapes.o Media.o
ifeq (${OS}, Windows_NT)
	g++ -o hw1 main.o Shapes.o Media.o -lgtest
else
	g++ -o hw1 main.o Shapes.o Media.o -lgtest -lpthread
endif

main.o: main.cpp utSort.h $(INC_DIR)/Sort.h
	g++ -std=gnu++0x -c main.cpp
Shapes.o: $(INC_DIR)/Shapes.h Shapes.cpp
	g++ -std=gnu++0x -c Shapes.cpp
Media.o: $(INC_DIR)/Media.h $(INC_DIR)/Shapes.h Media.cpp
	g++ -std=gnu++0x -c Media.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw1
>>>>>>> 6609119d1eb49b377bcf20c9302cfb855cb8253a
endif