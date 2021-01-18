package main
import "fmt"

func singleNumber(nums []int) int {
	var map_res map[int] int
	map_res = make(map[int]int)
	for _, j := range nums {
		map_res[j] += 1
	}
	for i := range map_res {
		if map_res[i] == 1 {
			return i
		}
	}
	return 0
}

func main() {
	fmt.Println(singleNumber([]int{2,2,1}))
}