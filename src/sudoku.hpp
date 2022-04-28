#pragma once

#include <array>
#include <string>

// struct for representing a coordinate
// used for indexing 2d sudoku array
struct Coordinate {
public:
    int row, col;

    inline Coordinate(int _row, int _col) {
        row = _row;
        col = _col;
    } 
};

// operator for incrementing coordinate
inline Coordinate operator++(Coordinate s);

// Sudoku solver class
class Sudoku {
public:
    // two-dimensional sudoku board array
    std::array<std::array<int, 9>, 9> board;
public:
    // constructor that calls parser
    Sudoku(std::string _board = "");

    // solve current board recursively
    bool solve(Coordinate square = Coordinate(0, 0));

    // check if the move is valid at given square
    bool is_valid(Coordinate square);

    // check if the given square is empty
    bool is_empty(Coordinate square);

    // check whether the board is solved or not
    bool is_solved();

    // parses given sudoku board
    void parse_board(std::string _board);

    // test the solver
    void test();

    // prints the entire sudoku board
    void print(); 
};