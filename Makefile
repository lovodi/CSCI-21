# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: Lovodi Lee
#
FLAGS = -Wall -Werror -Wextra -pedantic
# Target for programming challenge 3
# Date completed: 2-3-2014
pc3: pc3.cpp
	g++ $(FLAGS) -o pc3 pc3.cpp
pc4: pc4.cpp
	g++ $(FLAGS) -o pc4 pc4.cpp
pc5: pc5.cpp
	g++ $(FLAGS) -o pc5 pc5.cpp
pc6: pc6.cpp
	g++ $(FLAGS) -o pc6 pc6.cpp
pc7: pc7.cpp
	g++ $(FLAGS) -o pc7 pc7.cpp
pc8: pc8.cpp
	g++ $(FLAGS) -o pc8 pc8.cpp
pc9: pc9.cpp
	g++ $(FLAGS) -o pc9 pc9.cpp
pc10: pc10.cpp
	g++ $(FLAGS) -o pc10 pc10.cpp
pp1: pp1.cpp
	g++ $(FLAGS) -o pp1 pp1.cpp