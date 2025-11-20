#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int n, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[n] = true;

        for (auto neigh : adj[n]) {
            if (!visit[neigh]) visit[neigh] = true;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visit(n, false);
        int res = 0;

        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                res++; dfs(i, adj, visit);
            }
        }
        return res;
    }
};