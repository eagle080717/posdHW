all: hw8 shell

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp
list.o:list.cpp list.h
	g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++0x -c struct.cpp
main.o: main.cpp utScanner.h scanner.h  atom.h struct.h variable.h utParser.h parser.h utExp.h
	g++ -std=gnu++0x -c main.cpp
mainShell.o: mainShell.cpp scanner.h  atom.h struct.h variable.h parser.h
	g++ -std=gnu++0x -c mainShell.cpp

hw8: main.o atom.o list.o struct.o scanner.h utScanner.h utParser.h parser.h
ifeq (${OS}, Windows_NT)
	g++ -o hw8 main.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 main.o atom.o list.o struct.o -lgtest -lpthread
endif

shell: mainShell.o atom.o list.o struct.o scanner.h parser.h
ifeq (${OS}, Windows_NT)
	g++ -o shell mainShell.o atom.o list.o struct.o -lgtest
else
	g++ -o shell mainShell.o atom.o list.o struct.o -lgtest -lpthread
endif


clean:
	rm -f *.o hw8 shell
stat:
	wc *.h *.cpp
