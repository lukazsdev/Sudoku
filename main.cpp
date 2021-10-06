#include <iostream>
#include <string>
#include <vector>

#include "solver.h"

int main()
{
	std::vector<int> board;
	std::string input;

	std::cin >> input;

	for (auto i : input)
		board.push_back(std::stoi(std::string(1, i)));

	Solver solver = Solver(board);

	solver.printBoard();
	solver.solve();
}

