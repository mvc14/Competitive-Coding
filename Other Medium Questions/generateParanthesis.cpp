#include <bits/stdc++.h>

class Solution {
    public:
        vector<std::string> generateParenthesis(int n) {
            std::vector<std::string> result;
            std::function<void(std::string, int, int)> backtrack = [&](std::string current, int open, int close) {
                if (current.length() == 2 * n) {
                    result.push_back(current);
                    return;
                }
                if (open < n) {
                    backtrack(current + '(', open + 1, close);
                }
                if (close < open) {
                    backtrack(current + ')', open, close + 1);
                }
            };
            backtrack("", 0, 0);
            return result;
        }
};

int main() {
    return 0;
}

