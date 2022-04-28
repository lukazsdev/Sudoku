#include <iostream>
#include "sudoku.hpp"

// operator for incrementing coordinate
inline Coordinate operator++(Coordinate s) {
    if (s.col == 8) {
        s.col = 0;
        s.row++;
    } else {
        s.col++;
    }
    return s;
}

bool Sudoku::is_empty(Coordinate square) {
    return board[square.row][square.col] == 0;
}

bool Sudoku::is_solved() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::is_valid(Coordinate square) {
    int row = square.row;
    int col = square.col;
    int num = board[row][col];
    // check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num && i != col) {
            return false;
        }
    }
    // check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num && i != row) {
            return false;
        }
    }
    // check 3x3 square
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (board[i][j] == num && (i != row || j != col)) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::solve(Coordinate square) {
    if (is_solved()) {
        return true;
    }
    if (is_empty(square)) {
        for (int i = 1; i <= 9; i++) {
            board[square.row][square.col] = i;
            if (is_valid(square)) {
                if (solve(++square)) {
                    return true;
                }
            }
        }
        board[square.row][square.col] = 0;
        return false;
    } else {
        return solve(++square);
    }
}

void Sudoku::test() {
    std::string board = "000000002000000940003000005092305074840000000067098000000706000000900020408500360";
    Sudoku sudoku = Sudoku(board);
    sudoku.print();
    sudoku.solve();
    sudoku.print();
}

Sudoku::Sudoku(std::string _board) {
    parse_board(_board);
}

void Sudoku::parse_board(std::string _board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = _board[i * 9 + j] - '0';
        }
    }
}

void Sudoku::print() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}