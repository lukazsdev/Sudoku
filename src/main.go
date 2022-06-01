package main

func main() {
	var sudoku Sudoku
	sudoku.New("000000002000000940003000005092305074840000000067098000000706000000900020408500360")
	sudoku.Print()
	sudoku.Solve(Cell{0, 0})
	sudoku.Print()
}
