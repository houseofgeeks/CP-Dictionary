func linear_search(arr: inout [Int], key: Int)->String{
	for index in arr{
		if key == index{
			return "found"
		}
	}
	return "Not Found"
}

var arr = [1,2,3,7,5,6]
print(linear_search(arr: &arr,key: 2))

