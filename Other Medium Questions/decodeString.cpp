#include <stack>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string currentString;
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0'); // convert char to int
            } else if (ch == '[') {
                counts.push(k);
                result.push(currentString);
                k = 0;
                currentString.clear();
            } else if (ch == ']') {
                string temp = currentString;
                currentString = result.top();
                result.pop();
                int count = counts.top();
                counts.pop();
                for (int i = 0; i < count; i++) {
                    currentString += temp;
                }
            } else {
                currentString += ch;
            }
        }
        return currentString;
    }
};

int main() {
    Solution sol;
    string s = "3[a2[c]]";
    cout << sol.decodeString(s) << endl; // Output: "accaccacc"
    return 0;
}