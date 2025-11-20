#include <bits/stdc++.h>
using namespace std;


// too slow
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> res;
        
        for (auto& q : queries) {
            int left = q[0];
            int right = q[1];
            int k = q[2];

            string tmp = s.substr(left, right - left + 1);
            int val = checkPalindrome(tmp);

            (val / 2 <= k) ? res.push_back(true) : res.push_back(false);
        }

        return res;
    }

    int checkPalindrome(string &s) {
        unordered_map<char, int> map;
        
        for (auto c : s) map[c]++;

        int count = 0;
        for (auto [k, v] : map) {
            if (v % 2 != 0) {
                count++;
            }
        }

        return count;
    }
};