#all: madRace utAtom utVariable utScanner
all: hw7

hw7: mainIterator.o atom.o list.o struct.o iterator.h utIterator.h
	g++ -o hw7 mainIterator.o atom.o list.o struct.o -lgtest -lpthread

mainIterator.o: mainIterator.cpp utIterator.h
	g++ -std=c++11 -c mainIterator.cpp
atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp
list.o: list.cpp list.h
	g++ -std=c++11 -c list.cpp
struct.o: struct.cpp struct.h
	g++ -std=c++11 -c struct.cpp
#utTerm: mainTerm.o term.o struct.o var.o list.o
#	g++ -o utTerm mainTerm.o term.o var.o struct.o list.o -lgtest -lpthread
#mainTerm.o: mainTerm.cpp utTerm.h term.h var.h utStruct.h struct.h list.h utList.h
#	g++ -std=c++11 -c mainTerm.cpp
#term.o: term.h term.cpp
#	g++ -std=c++11 -c term.cpp
#struct.o: struct.h struct.cpp
#	g++ -std=c++11 -c struct.cpp
#var.o: var.h var.cpp
#g++ -std=c++11 -c var.cpp
#list.o: list.h list.cpp term.h var.h
#	g++ -std=c++11 -c list.cpp
clean:
	rm -f *.o hw7
stat:
	wc *.h *.cpp
