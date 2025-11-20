#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(endTime[i], startTime[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            auto [end, start, p] = jobs[i - 1];
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (get<0>(jobs[mid]) <= start) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            dp[i] = max(dp[i - 1], dp[l] + p);
        }
        return dp[n];
    }
};