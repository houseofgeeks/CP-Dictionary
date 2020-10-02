/* Program for printing the minimum no. of coins to achieve the amount. */

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e7;

/* Recursive Approach. */
int minm_coins_recursive(int n, int sum, vector<int> &C)
{
	/* Base Cases. */
	if (n <= 0) return INF;
	else if (sum <= 0) return 0;

	/* condition that current coin value is less than the current sum then we will
		take the minimum between taking the coin and not taking the coin. */
	else if (C[n - 1] <= sum)
		return min(1 + minm_coins_recursive(n, sum - C[n - 1], C),
		           minm_coins_recursive(n - 1, sum, C));

	/* condition when current coin value exceeds the current sum the
		we will not take the coin at nth position. */
	else return minm_coins_recursive(n - 1, sum, C);
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
	int ans = minm_coins_recursive(n, sum, C);
	if (ans > 1e6) cout << -1 << endl;
	else cout << ans << endl;

}
