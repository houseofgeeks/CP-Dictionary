/* Program for printing the minimum no. of coins to achieve the amount. */

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7;


/* Memoized version. */
int minm_coins_memoized(int n, int sum, vector<int> &C, vector<vector<int> > &memo)
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
		memo[n][sum] = min(1 + minm_coins_memoized(n, sum - C[n - 1], C, memo),
		                   minm_coins_memoized(n - 1, sum, C, memo));

		return memo[n][sum];
	}
	else return memo[n][sum] = minm_coins_memoized(n - 1, sum, C, memo);
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

	/* memo vector to store the previous results. */
	vector<vector<int> > memo(n + 1, vector<int>(sum + 1, -1));
	int ans = minm_coins_memoized(n, sum, C, memo);
	if (ans > 1e6) cout << -1 << endl;
	else cout << ans << endl;

}
