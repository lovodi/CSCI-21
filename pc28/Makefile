flags = -Wall -Wextra -Werror -pedantic

pc28: pc28.o Item.o FoodItem.o MagicItem.o
	g++ $(flags) pc28.o Item.o FoodItem.o MagicItem.o -o pc28

pc28.o: pc28.cpp Item.h FoodItem.h  
	g++ $(flags) -c pc28.cpp -o pc28.o
	
Item.o: Item.h Item.cpp
	g++ $(flags) -c Item.cpp -o Item.o
	
FoodItem.o: FoodItem.cpp FoodItem.h
	g++ $(flags) -c FoodItem.cpp -o FoodItem.o
	
MagicItem.o: MagicItem.h MagicItem.cpp
	g++ $(flags) -c MagicItem.cpp -o MagicItem.o
	
clean:
	rm *.o