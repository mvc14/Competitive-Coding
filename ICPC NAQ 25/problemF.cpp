#include <bits/stdc++.h>   
using namespace std;

// logic does not work; need to work on it later
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double badness = 0.0;
    double mean = 0.0;
    for (int i = 0; i < n; i++) {
        mean += a[i];
    }
    mean /= n;

    double standard_deviation = 0.0;
    for (int i = 0; i < n; i++) {
        standard_deviation += (a[i] - mean) * (a[i] - mean);
    }
    standard_deviation = sqrt(standard_deviation / n);
    cout << fixed << setprecision(10) << standard_deviation << endl;
    return 0;
}