/* Program for selection sort. */

#include<bits/stdc++.h>
using namespace std;

/* Selection sort function. */
void selection_sort(vector<int> &A)
{
	/* Size of the vector. */
	int n = A.size();

	/* Loop for the starting index of the unsorted part. */
	for (int i = 0; i < n; ++i)
	{
		/* variable to store the least element of the
		unsorted part and index of that element. */
		int minm = 1e6, in = -1;

		/* Loop for finding the minimum value in the sorted part. */
		for (int j = i; j < n; ++j)
		{
			if (A[j] < minm)
			{
				minm = A[j];
				in = j;
			}
		}

		/* Swapping the minimum value with the first element of the unsorted part. */
		swap(A[in], A[i]);
	}
}


int main()
{

	/* Size of Vector. */
	int n;
	cin >> n;

	vector<int> A(n);

	/* Inputing the values. */
	for (int i = 0; i < n; i++) cin >> A[i];

	/* Passing A as referance to selection_sort and updating it.*/
	selection_sort(A);

	/* Printing the final sorted vector. */
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << endl;

	return 0;
}


