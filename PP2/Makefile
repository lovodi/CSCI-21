FLAGS =  -Wno-newline-eof -Wall -Wextra -Werror -pedantic

pp2: Prize.o Box.o pp2.o
	g++ $(FLAGS) Prize.o Box.o pp2.o -o pp2

pp2.o: pp2.cpp
	g++ -c $(FLAGS) pp2.cpp -o pp2.o

Box.o: Box.h Box.cpp
	g++ -c $(FLAGS) Box.cpp -o Box.o

Prize.o: Prize.h Prize.cpp
	g++ -c $(FLAGS) Prize.cpp -o Prize.o
	
clean:
	rm -f *.o
	
cleanall: clean
	rm -f pp2;
	
