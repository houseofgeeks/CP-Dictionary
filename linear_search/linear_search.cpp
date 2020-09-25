#include <bits/stdc++.h>

using namespace std;

//parameters are linear_search(array address, size of array, key to find)
bool linear_search(int arr[], int size , int key) {

	for (int i = 0 ; i < size; i++) {
		if (key == arr[i])return true;
	}

	return false;
}

int main() {

	//example
	int arr[] = {2, 3, 4, 5, 7, 8};

	//linear_search function returns true if element is found and false if not found
	cout << linear_search(arr, 6, 3) << '\n';
	cout << linear_search(arr, 6, 1) << '\n';

	return 0;
}