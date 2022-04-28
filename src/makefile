out: main.o sudoku.o
	g++ main.o sudoku.o -o out

main.o: main.cpp
	g++ -c main.cpp

sudoku.o: sudoku.cpp sudoku.hpp
	g++ -c sudoku.cpp

clean:
	del /Q /S *.o *.exe