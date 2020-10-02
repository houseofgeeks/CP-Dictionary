/* Program for number of ways to acheive an amount. */

#include<bits/stdc++.h>
using namespace std;

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


	cout << number_of_ways_bottom_up(n, sum, C) << endl;

}
