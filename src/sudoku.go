package main

import "fmt"

const (
	MaxRows uint8 = 9
	MaxCols uint8 = 9
)

// sudoku board
type Sudoku struct {
	board [9][9]uint8
}

// sudoku cell
type Cell struct {
	row uint8
	col uint8
}

// move current cell forward
func forward(cell Cell) Cell {
	if cell.col == 8 {
		cell.col = 0
		cell.row++
	} else {
		cell.col++
	}
	return cell
}

// parse new sudoku board
func (sudoku *Sudoku) New(encoded string) {
	for row := 0; row < int(MaxRows); row++ {
		for col := 0; col < int(MaxCols); col++ {
			sudoku.board[row][col] = uint8(encoded[row*9+col]) - 48
		}
	}
}

// check if the move we have just made is valid
func (sudoku *Sudoku) isOk(cell Cell) bool {
	row := cell.row
	col := cell.col
	num := sudoku.board[row][col]

	// check row
	for currCol := 0; currCol < int(MaxCols); currCol++ {
		if sudoku.board[row][currCol] == num && currCol != int(col) {
			return false
		}
	}

	// check col
	for currRow := 0; currRow < int(MaxRows); currRow++ {
		if sudoku.board[currRow][col] == num && currRow != int(row) {
			return false
		}
	}

	// check 3 x 3 grid
	for currRow := (int(row) / 3) * 3; currRow < (int(row)/3)*3+3; currRow++ {
		for currCol := (int(col) / 3) * 3; currCol < (int(col)/3)*3+3; currCol++ {
			if sudoku.board[currRow][currCol] == num && (currRow != int(row) || currCol != int(col)) {
				return false
			}
		}
	}

	// is ok
	return true
}

// solve sudoku board
func (sudoku *Sudoku) Solve(cell Cell) bool {
	if cell.row == MaxRows && cell.col == 0 {
		return true
	}

	if sudoku.board[cell.row][cell.col] == 0 {
		for num := 1; num <= 9; num++ {
			sudoku.board[cell.row][cell.col] = uint8(num)

			if sudoku.isOk(cell) {
				if sudoku.Solve(forward(cell)) {
					return true
				}
			}

		}
		sudoku.board[cell.row][cell.col] = 0
		return false

	} else {
		return sudoku.Solve(forward(cell))
	}
}

// print sudoku board to console
func (sudoku *Sudoku) Print() {
	for row := 0; row < int(MaxRows); row++ {
		for col := 0; col < int(MaxCols); col++ {
			fmt.Print(sudoku.board[row][col], " ")
		}
		fmt.Println()
	}
	fmt.Println()
}
