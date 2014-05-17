flags = -Wall -Wextra -Werror -pedantic

pp4: pp4.o Driver.o BSTNode.o BSTree.o
	g++ $(flags) pp4.o Driver.o BSTNode.o BSTree.o -o pp4

pp4.o: pp4.cpp Driver.h BSTNode.h BSTree.h Word.h
	g++ $(flags) -c pp4.cpp -o pp4.o
	
Driver.o: Driver.h Driver.cpp
	g++ $(flags) -c Driver.cpp -o Driver.o
	
BSTNode.o: BSTNode.cpp BSTNode.h
	g++ $(flags) -c BSTNode.cpp -o BSTNode.o
	
BSTree.o: BSTree.cpp BSTree.h
	g++ $(flags) -c BSTree.cpp -o BSTree.o
	
clean:
	rm *.o

cleanall:
	rm *.o
	rm *.exe*