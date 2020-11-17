all:game

game:sokoban.o sokoban_main.o test_copy.o
	g++ -o game sokoban.o sokoban_main.o test_copy.o -lncursesw

sokoban_main.o:sokoban_main.cpp
	g++ -c -o sokoban_main.o sokoban_main.cpp -lncursesw

sokoban.o:sokoban.cpp
	g++ -c -o sokoban.o sokoban.cpp -lncursesw

test_copy.o:test_copy.cpp
	g++ -c -o test_copy.o test_copy.cpp -lncursesw
