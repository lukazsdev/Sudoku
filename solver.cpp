#include <iostream>
#include "solver.h"

Solver::Solver(std::vector<int> &board) 
{
	this->board = board;
}

bool Solver::isEmpty(int index)
{
	return (board[index] == 0) ? true : false;
}

bool Solver::isValid(int index)
{
	int row, col;
	row = index / 9;
	col = index - 9 * row;

	// rows and columns
	for (int i = 0; i < 9; i++)
	{
		if (board[i + row * 9] == board[index] && i != col)
			return false;

		else if (board[col + i * 9] == board[index] && i != row)
			return false;
	}
	
	// grids
	int gridRow = row / 3;
	int gridCol = col / 3;

	for (int i = gridRow * 3; i < gridRow * 3 + 3; i++) 
	{
		for (int j = gridCol * 3; j < gridCol * 3 + 3; j++) 
		{
			if ((board[j + i * 9] == board[index]) && (i != row) && (j != col)) 
				return false;
		}
	}

	return true;
}

bool Solver::isSolved()
{
	for (int i = 0; i < board.size(); i++)
	{
		if (isEmpty(i) == true || isValid(i) == false)
			return false;
	}
	
	return true;
}

bool Solver::solve(int index)
{
	if (index == board.size())
	{
		if (isSolved() == true)
		{
			printBoard();
			return true;
		}
		else
			return false; 
	}

	if (isEmpty(index) == true)
	{
		for (int i = 1; i <= 9; i++)
		{
			board[index] = i;
			if (isValid(index) == true)
			{
				bool node = solve(index + 1);
				if (node == true) { return true; }
				board[index] = 0;
			}
			else 
				continue; 
		}
		board[index] = 0;
		return false;
	}
	bool node = solve(index + 1);
	return node;
}

void Solver::printBoard()
{
	std::cout << "\n";
	for (int i = 0; i < board.size(); i++)
	{
		std::cout << board[i] << " ";
		if ((i + 1) % 9 == 0 && i != 0)
			std::cout << "\n";
	}
}
