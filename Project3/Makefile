flags= -Wall -Wextra -Werror -pedantic

pp3: pp3.o DLNode.o DLList.o Operator.o
	g++ $(flags) pp3.o DLNode.o DLList.o Operator.o -o pp3

pp3.o: pp3.cpp
	g++ $(flags) -c pp3.cpp -o pp3.o

DLNode.o: DLNode.cpp DLNode.h
	g++ $(flags) -c DLNode.cpp -o DLNode.o

DLList.o: DLList.cpp DLList.h
	g++ $(flags) -c DLList.cpp -o DLList.o

Operator.o: Operator.h Operator.cpp
	g++ $(flags) -c Operator.cpp -o Operator.o