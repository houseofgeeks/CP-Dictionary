/* Program for number of ways to acheive an amount. */

#include<bits/stdc++.h>
using namespace std;

/* Recursive Approach. */
int number_of_ways_recursive(int n, int sum, vector<int> &C)
{
	/* Base Cases. */
	if (sum <= 0) return 1;
	else if (n <= 0) return 0;

	/* condition that current coin value is less than the current sum
		then either we can take the coin or not take the coin. */
	else if (C[n - 1] <= sum)
		return number_of_ways_recursive(n, sum - C[n - 1], C)
		       + number_of_ways_recursive(n - 1, sum, C);

	/* condition when current coin value exceeds the current sum the
		we will not take the coin at nth position. */
	else return number_of_ways_recursive(n - 1, sum, C);
}


/* Memoized version. */
int number_of_ways_memoized(int n, int sum, vector<int> &C, vector<vector<int>> &memo)
{
	/* Base cases. */
	if (sum <= 0) return memo[n][sum] = 1;
	else if (n <= 0) return memo[n][sum] = 0;

	/* If number of ways for current n and sum is already
		calculated the we don't need to compute it again. */
	else if (memo[n][sum] != -1) return memo[n][sum];

	/* condition when ways for current n and sum is not computed then
		we will compute it and store in vector memo. */
	else if (C[n - 1] <= sum)
	{
		memo[n][sum] = number_of_ways_memoized(n, sum - C[n - 1], C, memo)
		               + number_of_ways_memoized(n - 1, sum, C, memo);

		return memo[n][sum];
	}
	else return memo[n][sum] = number_of_ways_memoized(n - 1, sum, C, memo);
}


int number_of_ways_bottom_up(int n, int sum, vector<int> &C)
{
	/* dp vector to store the results. */
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

	/* We will compute the all the possible combinations of n and sum
		and store it in the dp vector. */
	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 0; j < sum + 1; ++j)
		{
			/* Initial cases when sum is 0 or we don't have any coin. */
			if (j == 0) dp[i][j] = 1;
			else if (i == 0) dp[i][j] = 0;

			else
			{
				/*If current coin value is less than than the current sum then we can either
					take the coin or leave it. */
				if (C[i - 1] <= j) dp[i][j] = dp[i][j - C[i - 1]] + dp[i - 1][j];

				/* When coin value exceeds the current sum then we leave that coin. */
				else dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][sum];
}



int main()
{

	/* Number of coins. */
	int n;
	cin >> n;

	/*Values of each coin. */
	vector<int> C(n);

	for (int i = 0; i < n; i++)	cin >> C[i];

	/* Amount we want to achieve. */
	int sum;
	cin >> sum;


	cout << number_of_ways_recursive(n, sum, C) << endl;

	/* memo vector to store the previous results. */
	vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
	cout << number_of_ways_memoized(n, sum, C, memo) << endl;


	cout << number_of_ways_bottom_up(n, sum, C) << endl;

}
