#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            if (n == 0) return "";
            vector<vector<bool>> dp(n, vector<bool>(n, false));
            int maxLength = 1;
            int start = 0;

            for (int i = 0; i < n; i++) {
                dp[i][i] = true; // Every single character is a palindrome
            }
            



        }



};  