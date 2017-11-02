#INC_DIR = include
#################################################################################
#all: utAtom utVariable utStruct hw4
all: hw5
#################################################################################
#utAtom: mainAtom.o
#ifeq (${OS}, Windows_NT)
#	g++ -o utAtom mainAtom.o -lgtest
#else
#	g++ -o utAtom mainAtom.o -lgtest -lpthread
#endif

#mainAtom.o: atom.h utAtom.h mainAtom.cpp
#	g++ -std=gnu++0x -c mainAtom.cpp
#################################################################################
#utVariable: mainVariable.o
#ifeq (${OS}, Windows_NT)
#	g++ -o utVariable mainVariable.o -lgtest
#else
#	g++ -o utVariable mainVariable.o -lgtest -lpthread
#endif

#mainVariable.o: atom.h number.h variable.h struct.h utVariable.h mainVariable.cpp
#	g++ -std=gnu++0x -c mainVariable.cpp
#################################################################################
#utStruct: mainStruct.o
#ifeq (${OS}, Windows_NT)
#	g++ -o utStruct mainStruct.o -lgtest
#else
#	g++ -o utStruct mainStruct.o -lgtest -lpthread
#endif

#mainStruct.o: atom.h number.h variable.h struct.h utStruct.h mainStruct.cpp
#	g++ -std=gnu++0x -c mainStruct.cpp
#################################################################################
hw5: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 main.o -lgtest
else
	g++ -o hw5 main.o -lgtest -lpthread
endif

main.o:	atom.h number.h struct.h variable.h list.h global.h scanner.h parser.h utParser.h main.cpp
	g++ -std=gnu++0x -c main.cpp
#################################################################################
clean:
ifeq (${OS}, Windows_NT)
#	del *.o *.exe utAtom utVariable utStruct hw4
	del *.o *.exe hw5
else
#	rm -f *.o utAtom utVariable utStruct hw4
	rm -f *.o hw5
endif