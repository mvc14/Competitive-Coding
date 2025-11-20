#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        set<char> seen;
        int left = 0, right = 0, res = 0;

        while (right < s.size()) {
            if (seen.find(s[right]) == seen.end()) {
                seen.insert(s[right]);
                res = max(res, right - left +1);
                right++;
            } else {
                seen.erase(s[left]);
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string s1 = "abcabc";
    cout << s.lengthOfLongestSubstring(s1) << endl;
    return 0;
}

  
