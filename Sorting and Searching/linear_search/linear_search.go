package main

import "fmt"

func linear_search (size int, key int, arr []int) string{
	
	for i := 0; i < size; i++ {
    	if arr[i]==key{
			return "found"
		}
	}
	
	return "not found"

}

func main() {

	arr := []int{1, 2, 3, 4, 5}
	ans := linear_search(5,2,arr)
	fmt.Println(ans)
	
}
