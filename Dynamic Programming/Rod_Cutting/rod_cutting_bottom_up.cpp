/* Program for printing the maximim cost of cutting the rod. */

#include<bits/stdc++.h>
using namespace std;

int max_profit_bottom_up(int size, int n, vector<int> &length, vector<int> &cost)
{
	/* dp vector to store the results. */
	vector<vector<int> > dp(size + 1, vector<int>(n + 1, 0));

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
