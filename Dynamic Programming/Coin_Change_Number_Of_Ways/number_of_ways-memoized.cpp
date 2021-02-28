/* Program for number of ways to acheive an amount. */

#include<bits/stdc++.h>
using namespace std;


/* Memoized version. */
int number_of_ways_memoized(int n, int sum, vector<int> &C, vector<vector<int> > &memo)
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
	cout << number_of_ways_memoized(n, sum, C, memo) << endl;

}
