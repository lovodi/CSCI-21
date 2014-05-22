flags= -Wall -Wextra -Werror -pedantic -Wno-newline-eof

pp4: Driver.o Word.o pp4.o 
	g++ $(flags) pp4.o Driver.o Word.o -o pp4

Driver.o: Driver.h Driver.cpp BSTNode.h BSTree.h
	g++ $(flags) -c Driver.cpp -o Driver.o

pp4.o: pp4.cpp BSTNode.h BSTree.h
	g++ $(flags) -c pp4.cpp -o pp4.o

Word.o: Word.cpp
	g++ $(flags) -c Word.cpp -o Word.o

clean:
	rm *.o