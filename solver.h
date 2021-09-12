#include <vector>

#ifndef SOLVER_H
#define SOLVER_H

class Solver
{
private:
	std::vector<int> board;

public:
	Solver(std::vector<int> &board);

	bool solve(int index = 0);
	bool isEmpty(int index);
	bool isValid(int index);
	bool isSolved();
	void printBoard();
};

#endif
