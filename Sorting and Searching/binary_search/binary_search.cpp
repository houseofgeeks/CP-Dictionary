
#include <bits/stdc++.h> // contains all header files of c++14

using namespace std;

//parameters are bnary_search(array address, size of array, key to find)
bool is_sorted(int intArray[], int size) {//need to pass in an integer array and the size of said array, question why not use vector since in c++
	if (size < 1) {
		return false;
	}
	int mid = size / 2;
	for (unsigned int i = 0; i < size - 1; i++) {
		if (intArray[i] > intArray[i + 1]) {
			return false;
		}
	}
	return true;
}
int binary_search(int arr[], int n , int key) {
	int start=0; // first index of array
	int end=n-1; // last index of array
	
	while(start<=end)
	{
		int mid = start + (end - start) / 2; 
		
		if(arr[mid]==key) // if the element is present at the middle itself
		return mid;
		
		else if(arr[mid]>key) // if element is smaller than mid , then it can be present in the left subarray only
		end=mid-1;
		
		else // else the element can only be present in the right subarray
		start=mid+1;
	}

	return -1;

	}
}
int main() {

	//example
	int arr[] = {1 , 2 , 5 , 7 , 9 , 11};
	int arrSize = 6;
	//Note : Make sure the array is in sorted order before performing binary search
	if (is_sorted(arr, arrSize) == false) {
		return -1;
	}
	/*binary_search function returns the index of the element if the element is found
	otherwise it returns -1 */
	cout << binary_search(arr, 6, 7) << '\n';
	cout << binary_search(arr, 6, 3) << '\n';

	return 0;
}
