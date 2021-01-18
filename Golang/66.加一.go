package main
import "fmt"

func plusOne(digits []int) []int {
	length := len(digits)
	for i := length - 1; i >= 0; i-- {
		digits[i] += 1
		digits[i] %= 10
		if digits[i] != 0 {
			return digits
		}
	}
	return append([]int{1}, digits...)
}

func main() {
	fmt.Println(plusOne([]int {1,2,3}))
}