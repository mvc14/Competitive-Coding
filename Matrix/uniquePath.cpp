#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1; // Starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j]; // From top
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1]; // From left
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};