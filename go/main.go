package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("level3_2.in")
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	outputFile, err := os.Create("output3_2")
	if err != nil {
		fmt.Println("Error creating output file:", err)
		return
	}
	defer outputFile.Close()

	var N int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &N)

	for i := 0; i < N; i++ {
		var width, height int
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &width, &height)

		lawn := make([][]rune, height)
		for j := 0; j < height; j++ {
			scanner.Scan()
			lawn[j] = []rune(scanner.Text())
		}

		var path string
		scanner.Scan()
		path = scanner.Text()

		result := "INVALID"
		if isValidPath(lawn, path) {
			result = "VALID"
		}

		fmt.Println(result)
		outputFile.WriteString(result + "\n")
	}
}

func isValidPath(lawn [][]rune, path string) bool {
	x, y := 0, 0
	visited := make(map[[2]int]bool)
	for _, dir := range path {
		visited[[2]int{x, y}] = true
		switch dir {
		case 'S':
			y++
		case 'W':
			y--
		case 'A':
			x--
		case 'D':
			x++
		}
		if x < 0 || y < 0 || x >= len(lawn[0]) || y >= len(lawn) || lawn[y][x] == 'X' || visited[[2]int{x, y}] {
			return false
		}
	}
	return true
}
