#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e2; // Max matrix size in both dimensions

int prefix_sum[MAX][MAX]; // Pre-processed prefix sum matrix
bool prefix_sum_ready = false;

void build_prefix_sum(int A[MAX][MAX], int n, int m) {
    // Initialize first row and column with zeros
    for (int i = 0; i <= n; i++) {
        prefix_sum[i][0] = 0;
        prefix_sum[0][i] = 0;
    }

    // Build prefix sum matrix using inclusion-exclusion principle
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix_sum[i][j] = A[i - 1][j - 1];
            prefix_sum[i][j] += prefix_sum[i - 1][j];
            prefix_sum[i][j] += prefix_sum[i][j - 1];
            prefix_sum[i][j] -= prefix_sum[i - 1][j - 1];
        }
    }
}

int range_sum_query(int A[MAX][MAX], int n, int m, int start_row, int start_col, int end_row, int end_col) {
    // Build prefix sum matrix if not already built
    if (!prefix_sum_ready) {
        build_prefix_sum(A, n, m);
        prefix_sum_ready = true;
    }

    // Compute range sum using inclusion-exclusion principle
    int ans = prefix_sum[end_row][end_col];
    ans -= prefix_sum[start_row - 1][end_col];
    ans -= prefix_sum[end_row][start_col - 1];
    ans += prefix_sum[start_row - 1][start_col - 1];

    return ans;
}

int main() {
    int A[MAX][MAX] = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 6},
        {3, 4, 5, 6, 7},
        {4, 5, 6, 7, 8},
        {5, 6, 7, 8, 9},
    };

    // Sum between (1, 2) and (3, 4) (1-based indexing)
    cout << range_sum_query(A, 5, 5, 1, 2, 3, 4) << "\n";
}