#include <bits/stdc++.h>
using namespace std;

// priority queue notes 
/*

--- Default Case --- 
priority_queue<int> pq; // will return the max elem always in O(1); insertion log n


-- min heap -- 
priority_queue<int, vector<int>, greater<int>> pq; // returns the smallest elem;

struct Compare {
    bool operator()(Node& a, Node& b) {
    return a.priority < b.priority;
    }
}
*/

class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        unordered_map<int, int> map;
        vector<int> res;

        for (int n : nums) map[n]++;

        for (auto [k, v] : map) {
            pq.push({v, k});
        }

        int count = 0;
        while (count < k) {
            res.push_back(pq.top().second); pq.pop();
            count++;
        }
    }
};