#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    int i, j; // starting coordinates
    cin >> i >> j;

    int x, y; // destination coordinates
    cin >> x >> y;  

    int res = 0;
    vector<vector<int>> grid(r, vector<int>(c, 0));

    for(int m = 0; m < r; m++) {
        for(int n = 0; n < c; n++) {
            cin >> grid[m][n];
        }
    }

    queue<pair<int, int>> q;
    q.push({i-1, j-1});
    grid[i-1][j-1] = 1; // mark as visited

    vector<pair<int, int>> directions = {{-1, 0}, {0,1}, {1, 0}}; // top, forward, or down (change direction)
    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++) {
            auto pair = q.front();
            q.pop();
            for (auto dir : directions) {
                int new_x = pair.first + dir.first;
                int new_y = pair.second + dir.second;
                if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c && grid[new_x][new_y] == 0) {
                    q.push({new_x, new_y});
                    grid[new_x][new_y] = 1;
                    if (new_x == x-1 && new_y == y-1) { 
                        res = 1;
                        break;
                    }
                }
            }
        }
    }

    cout << res << endl;
    
    return res; // if_possible ? 1 : 0; 
}