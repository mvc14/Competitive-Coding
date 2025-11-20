#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;


        if (grid.size() ==1 && grid[0][0] == 0) return 1;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [x , y] = q.front(); q.pop();
            int dist = grid[x][y];

            for (int i = 0; i < 8; i++) {
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;

                if (nx == grid.size() -1 && ny == grid.size() -1) {
                    return dist + 1;
                }

                if (inBounds(grid, nx, ny) && grid[nx][ny] == 0) {
                    grid[nx][ny] = dist + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }

    bool inBounds(vector<vector<int>>& grid, int x, int y) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }
};