#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // frequency map 
        map<char, int> map; // A, 3
        priority_queue<pair<int, int>, vector<int, int>> pq;

        for (auto& a : tasks) {
            map[a]++;
        }

        int tmp = 0;
        for (auto [k, v] : map) {
            pq.push({v, k});
        }

        int count = 0;
        int n = pq.size(); // unique tasks
        int k = 0;

        while (k < tasks.size()) {
            
            if (tmp >= n) {
                count++;
                continue;
            }

            

            


        }


        k++;
    }
};