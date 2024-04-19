package main
import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
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
        if isValidPath(lawn, path) {
            fmt.Println("VALID")
        } else {
            fmt.Println("INVALID")
        }
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
            x--
        case 'A':
            y--
        case 'D':
            x++
        }
        if x < 0 || y < 0 || x >= len(lawn[0]) || y >= len(lawn) || lawn[y][x] == 'X' || visited[[2]int{x, y}] {
            return false
        }
    }
    return true
}

