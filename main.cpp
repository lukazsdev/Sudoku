#include <iostream>
#include <string>
#include <vector>

#include "solver.h"

int main()
{
	std::vector<int> board;
	std::string input;

	//input sudoku board as a string
	std::cin >> input;

	for (auto &c : input)
		board.push_back(std::stoi(std::string(1, c)));

	Solver solver = Solver(board);

	solver.printBoard();
	solver.solve();
}

