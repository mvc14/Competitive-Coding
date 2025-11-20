#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path{0};
        vector<vector<int>> res;
        backtrack(0, path, res, graph);
        return res;
    }

    void backtrack(int idx, vector<int>& path, vector<vector<int>>& res,
                    vector<vector<int>>& graph) {

        int target = int(graph.size() -1);
        if (idx == target) {
            res.push_back(vector(path));
            return;
        }

        for (int node : graph[idx]) {
            path.push_back(node);
            backtrack(node, path, res, graph);
            path.pop_back();
        }
    }
};