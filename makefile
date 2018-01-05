all: hw8

atom.o: atom.cpp atom.h variable.h
	g++ -std=c++11 -c atom.cpp
list.o:list.cpp list.h
	g++ -std=c++11 -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=c++11 -c struct.cpp

hw8: main.o atom.o list.o struct.o scanner.h utScanner.h utParser.h parser.h
ifeq (${OS}, Windows_NT)
	g++ -o hw8 main.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 main.o atom.o list.o struct.o -lgtest -lpthread
endif

main.o: main.cpp utScanner.h scanner.h  atom.h struct.h variable.h  utParser.h parser.h utExp.h
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o hw8
stat:
	wc *.h *.cpp
