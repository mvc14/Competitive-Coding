#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visit, int n) {
        visit[n] = true;

        for (auto neigh : adj[n]) {
            if (!visit[neigh])
                dfs(adj, visit, neigh);
        }
    }

    bool helper(vector<bool>& visit) {
        for (bool v : visit) if (!v) return false;
        return true;
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());

        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);

        for (int i = 0; i < logs.size(); ++i) {
            int time = logs[i][0];
            int x = logs[i][1];
            int y = logs[i][2];

            adj[x].push_back(y);
            adj[y].push_back(x);

            fill(visit.begin(), visit.end(), false);
            dfs(adj, visit, 0);

            if (helper(visit)) return time;
        } 
        
        return -1;
    }
};