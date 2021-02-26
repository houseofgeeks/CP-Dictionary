/* Program for printing the maximim cost of cutting the rod. */

#include<bits/stdc++.h>
using namespace std;

/* Memoized version. */
int max_profit_memoized(int size, int n, vector<int> &length, vector<int> &cost, vector<vector<int> > &memo)
{
	/* Base cases. */
	if (n == 0 || size == 0) return memo[size][n] = 0;


	/* If cost for current n and size is already
		calculated the we don't need to compute it again. */
	else if (memo[size][n] != -1) return memo[size][n];

	/*If length is less then the current size of the rod  we will take the maximum
	cost between cutting the rod and not cutting the rod. */
	else if (length[n - 1] <= size)
	{
		memo[size][n] = max(cost[n - 1] + max_profit_memoized(size - length[n - 1], n, length, cost, memo),
		                    max_profit_memoized(size, n - 1, length, cost, memo));

		return memo[size][n];
	}

	/* Not cutting case. */
	else return memo[size][n] = max_profit_memoized(size, n - 1, length, cost, memo);
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


	/* memo vector to store the previous results. */
	vector<vector<int> > memo(size + 1, vector<int>(n + 1, -1));
	cout << max_profit_memoized(size, n, length, cost, memo) << endl;

}

/*
SAMPLE INPUT:
8
8
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20
OUTPUT: 22
*/
