FLAGS= -Wall -Wextra -Werror -pedantic

pc26: pc26.o BSTNode.o BSTree.o
	g++ $(FLAGS) -o pc26 pc26.o  BSTree.o BSTNode.o
pc26.o: pc26.cpp
	g++ $(FLAGS) -c pc26.cpp -o pc26.o
BSTNode.o: BSTNode.cpp BSTNode.h
	g++ $(FLAGS) -c BSTNode.cpp -o BSTNode.o
BSTree.o: BSTree.cpp BSTree.h
	g++ $(FLAGS) -c BSTree.cpp -o BSTree.o