flags= -Wall -Wextra -Werror -pedantic

pc25: pc25.o BSTNode.o
	g++ $(flags) -o pc25 pc25.o  BSTNode.o
	
pc25.o: pc25.cpp
	g++ $(flags) -c pc25.cpp -o pc25.o

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ $(flags) -c BSTNode.cpp -o BSTNode.o
