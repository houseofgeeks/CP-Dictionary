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


/* Memoized version. */
int max_profit_memoized(int size, int n, vector<int> &length, vector<int> &cost, vector<vector<int>> &memo)
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


int max_profit_bottom_up(int size, int n, vector<int> &length, vector<int> &cost)
{
	/* dp vector to store the results. */
	vector<vector<int>> dp(size + 1, vector<int>(n + 1, 0));

	/* We will compute the all the possible combinations of cost of
	cutting the rod and store it in the dp vector. */
	for (int i = 0; i < size + 1; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			/* Initial cases when length of rod is 0 or no possible choice left. */
			if (i == 0) dp[i][j] = 0;
			else if (j == 0) dp[i][j] = 0;

			else
			{
				/*If length is less then the current size of the rod  we will take the maximum
				 cost between cutting the rod and not cutting the rod. */
				if (length[j - 1] <= i)
					dp[i][j] = max(cost[j - 1] + dp[i - length[j - 1]][j] , dp[i][j - 1]);

				/* When length is more than the size then we will not be able to cut the rod. */
				else dp[i][j] = dp[i][j - 1];
			}
		}
	}

	return dp[size][n];
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

	/* memo vector to store the previous results. */
	vector<vector<int>> memo(size + 1, vector<int>(n + 1, -1));
	cout << max_profit_memoized(size, n, length, cost, memo) << endl;


	cout << max_profit_bottom_up(size, n, length, cost) << endl;

}

/*
SAMPLE INPUT:
8
8
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20
OUTPUT: 22
*/
