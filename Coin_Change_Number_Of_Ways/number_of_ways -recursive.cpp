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

}
