#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int n = profits.size();

       vector<pair<int, int>> map;

       for (int i = 0; i < n; ++i) {
            map.push_back({capital[i], profits[i]});
       }

       sort(map.begin(), map.end()); // choose cheaper projects first 
       priority_queue<int> profit;

       int i = 0;
       while (k--) {

            while (i < n && map[i].first <= w) {
                profit.push(map[i].second);
                i++;
            }


            if (profit.empty()) break;

            w += profit.top(); profit.pop();
       }

       return w;
    }
};