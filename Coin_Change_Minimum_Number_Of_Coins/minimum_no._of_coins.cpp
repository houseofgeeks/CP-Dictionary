/* Program for printing the minimum no. of coins to achieve the amount. */

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7;

/* Recursive Approach. */
int number_of_ways_recursive(int n, int sum, vector<int> &C)
{
	/* Base Cases. */
	if (n <= 0) return INF;
	else if (sum <= 0) return 0;

	/* condition that current coin value is less than the current sum then we will
		take the minimum between taking the coin and not taking the coin. */
	else if (C[n - 1] <= sum)
		return min(1 + number_of_ways_recursive(n, sum - C[n - 1], C),
		           number_of_ways_recursive(n - 1, sum, C));

	/* condition when current coin value exceeds the current sum the
		we will not take the coin at nth position. */
	else return number_of_ways_recursive(n - 1, sum, C);
}


/* Memoized version. */
int number_of_ways_memoized(int n, int sum, vector<int> &C, vector<vector<int>> &memo)
{
	/* Base cases. */
	if (n <= 0) return memo[n][sum] = INF;
	else if (sum <= 0) return memo[n][sum] = 0;


	/* If number of ways for current n and sum is already
		calculated the we don't need to compute it again. */
	else if (memo[n][sum] != -1) return memo[n][sum];

	/* condition when ways for current n and sum is not computed then
		we will compute it and store in vector memo. */
	else if (C[n - 1] <= sum)
	{
		memo[n][sum] = min(1 + number_of_ways_memoized(n, sum - C[n - 1], C, memo),
		                   number_of_ways_memoized(n - 1, sum, C, memo));

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
			if (i == 0) dp[i][j] = INF;
			else if (j == 0) dp[i][j] = 0;

			else
			{
				/*If current coin value is less then we will take the minimum of
					taking the coin or leaveing it. */
				if (C[i - 1] <= j) dp[i][j] = min(1 + dp[i][j - C[i - 1]] , dp[i - 1][j]);

				/* When coin value exceeds the current sum then we leave that coin. */
				else dp[i][j] = dp[i - 1][j];
			}
		}
	}

	if (dp[n][sum] > 1e6) return -1;
	else return dp[n][sum];
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

	/* If answer will exceed 10^6 then there is no possible combination. */
	int ans = number_of_ways_recursive(n, sum, C);
	if (ans > 1e6) cout << -1 << endl;
	else cout << ans << endl;

	/* memo vector to store the previous results. */
	vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
	ans = number_of_ways_memoized(n, sum, C, memo);
	if (ans > 1e6) cout << -1 << endl;
	else cout << ans << endl;


	cout << number_of_ways_bottom_up(n, sum, C) << endl;

}
