/* Program for printing the maximim cost of cutting the rod. */

#include<bits/stdc++.h>
using namespace std;

/* Recursive Approach. */
int max_profit_recursive(int size, int n, vector<int> &length, vector<int> &cost)
{
	/* Base Cases. */
	if (n == 0 || size == 0) return 0;

	/*If length is less then the current size of the rod  we will take the maximum
		cost between cutting the rod and not cutting the rod. */
	else if (length[n - 1] <= size)
		return max(cost[n - 1] + max_profit_recursive(size - length[n - 1], n, length, cost),
		           max_profit_recursive(size, n - 1, length, cost));

	/* When length is more than the size then we will not be able to cut the rod. */
	else return max_profit_recursive(size, n - 1, length, cost);
}


int main()
{

	/* size of rod. */
	int size;
	cin >> size;

	/* Number of different sizes of rod. */
	int n;
	cin >> n;

	/* Lengths of different sizes of rod and their corresponding costs. */
	vector<int> length(n), cost(n);

	for (int i = 0; i < n; i++)	cin >> length[i];
	for (int i = 0; i < n; i++)	cin >> cost[i];


	cout << max_profit_recursive(size, n, length, cost) << endl;

}

/*
SAMPLE INPUT:
8
8
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20
OUTPUT: 22
*/
