#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> result(5, 0);
        
        int l_up[][2] = {
            {0,-1}, {-1,0}, 
            {-1,-1}, 
            {0,0}
        };

        int l_down[][2] = {
            {0,0}, {0,-1}, 
            {-1,0}, 
            {-1,-1}
        };

        int r_up[][2] = {
            {0,0}, {-1,0}, 
            {0,-1}, 
            {-1,-1}
        };

        int r_down[][2] = {
            {0,-1}, {0,0}, 
            {-1,-1}, 
            {-1,0}
        };

        for (const auto& coord : coordinates) {
            int x = coord[0];
            int y = coord[1];

            for (int i = 0; i < 4; ++i) {
                int x1 = x + l_up[i][0];
                int y1 = y + l_up[i][1];
                int x2 = x + l_down[i][0];
                int y2 = y + l_down[i][1];

                if (x1 >= 0 && x2 < m - 1 && y1 >= 0 && y2 < n - 1) {
                   if (contains(coordinates, x1, y1) && contains(coordinates, x2, y2)) {
                        result[4]++;
                    } else if (contains(coordinates, x1, y1) || contains(coordinates, x2, y2)) {
                        result[3]++;
                    } else {
                        result[2]++;
                    }
                }
            }

            for (int i = 0; i < 4; ++i) {
                int x1 = x + r_up[i][0];
                int y1 = y + r_up[i][1];
                int x2 = x + r_down[i][0];
                int y2 = y + r_down[i][1];

                if (x1 >= 0 && x2 < m - 1 && y1 >= 0 && y2 < n - 1) {
                     if (contains(coordinates, x1, y1) && contains(coordinates, x2, y2)) {
                            result[4]++;
                      } else if (contains(coordinates, x1, y1) || contains(coordinates, x2, y2)) {
                            result[3]++;
                      } else {
                            result[2]++;
                      }
                }
            }
        }
    }


    bool contains(vector<vector<int>>& blocks, int x, int y) {
        for (const auto& block : blocks) {
            if (block[0] == x && block[1] == y) {
                return true;
            }
        }
        return false;
    }
};