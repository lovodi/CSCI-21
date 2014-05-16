flags= -Wall -Wextra -Werror -pedantic

pp4: pp4.o BSTNode.o BSTree.o Driver.o
	g++ $(flags) pp4.o BSTNode.o BSTree.o Driver.o -o pp4

pp4.o: pp4.cpp
	g++ $(flags) -c pp4.cpp -o pp4.o

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ $(flags) -c BSTNode.cpp -o BSTNode.o

BSTree.o: BSTree.cpp BSTree.h
	g++ $(flags) -c BSTree.cpp -o BSTree.o

Driver.o: Driver.h Driver.cpp
	g++ $(flags) -c Driver.cpp -o Driver.o