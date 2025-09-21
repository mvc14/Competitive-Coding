using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        vector<int> res;
        if (mat.size() == 0) return res;
        int i = 0, j = 0;
        int n = mat[0].size(), m = mat.size();
        bool left = true;

        for (int k = 0; k < m * n; ++k) {
            res[k] = mat[i][j];
            if (left) { // moving up-right
                if (j == n - 1) { 
                    i++; left = false; 
                }
                else if (i == 0) { 
                    j++; left = false; 
                }
                else { 
                    i--; j++; 
                }
            } else { // moving down-left
                if (i == m - 1) { 
                    j++; left = true; 
                }
                else if (j == 0) {
                    i++; left = true; 
                }
                else {
                    i++; j--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result = sol.findDiagonalOrder(mat);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
        