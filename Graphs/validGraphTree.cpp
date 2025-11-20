#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        stack<pair<int, int>> stack; // parent, node 
        set<int> seen;
        stack.push({-1, 0});

        while (!stack.empty()) {
            auto [parent, node] = stack.top(); stack.pop();

            if (seen.count(node)) return false;
            seen.insert(node);
            
            for (int neighbor : adj[node]) {
                if (neighbor == parent) continue;
                stack.push({node, neighbor});
            }
        }

        return seen.size() == n;
    }
};