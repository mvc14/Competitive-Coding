#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        if (strs.size() <= 1) {
            res.push_back(strs);
            return res;
        }

        // "nat", "tan"
        unordered_map<string, vector<string>> map;
        for (auto& a : strs) {
            
            vector<char> tmp(a.begin(), a.end());
            sort(tmp.begin(), tmp.end());
            string word(tmp.begin(), tmp.end());
            
            if (map.find(word) == map.end()) {
                map[word] = vector<string>();
            } else {
                map[word].push_back(a);
            }
        }

        for (auto& [k, v] : map) {
            vector<string> vec;
            for (auto i : v) {
                vec.push_back(i);
            }

            res.push_back(vec);
        }

        return res;
    }
};


int main() {
    Solution s;
    vector<string> v = {"nat", "tan", "a", "ass", "sas"};
    
    s.groupAnagrams(v);


    return 0;
}