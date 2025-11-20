#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    vector<int> a(x);

    for (int i = 0; i < x; i++) {
        cin >> a[i];    
    }

    sort(a.begin(), a.end());
    auto new_a = unique(a.begin(), a.end()); // max unique elements
    a.erase(new_a, a.end());
    
    return a.size() - 1 < y ? a.size() - 1 : y;
}