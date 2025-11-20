#include <bits/stdc++.h>
using namespace std;

// will need DSU learnings, to do later!!!

class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto d : dir) {
            int nx = i + d.first;
            int ny = j + d.second;

            if (inBounds(nx, ny, m, n) && !visited[nx][ny] && matrix[nx][ny] == 1) {
                visited[nx][ny] = true;
            }
        }
    }


    bool inBounds(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        vector<int> res(positions.size());
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (auto position : positions) {
            int x = position[0], y = position[1];
            matrix[x][y] = 1;
        }

        int idx = 0, count = 0;
        // bool flag = false/;

        
        for (auto position : positions) {
            int x = position[0], y = position[1];

            if (!visited[x][y]) {
                count++;
                bfs(x, y, matrix, visited);
            }

            res[idx++] = count;
        }

        return res;
    }
};
