flags = -Wall -Wextra -Werror -pedantic

pp4: pp4.o
	g++ $(flags) pp4.o -o pp4

pp4.o: pp4.cpp BSTNode.h BSTree.h Word.h
	g++ $(flags) -c pp4.cpp -o pp4.o

clean:
	rm *.o

cleanall:
	rm *.o
	rm *.exe*