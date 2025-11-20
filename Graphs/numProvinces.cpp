#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& graph, vector<bool>& visit, int i) {
        visit[i] = true;

        for (int k = 0; k < graph.size(); ++k) {
            if (graph[i][k] && !visit[k]) {
                dfs(graph, visit, k);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visit(n, false);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                count++; dfs(isConnected, visit, i);
            }
        }

        return count;

    }
};