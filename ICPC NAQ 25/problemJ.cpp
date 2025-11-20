#include <bits/stdc++.h>
using namespace std;


// BINGO problem

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a(100);

    for (int i = 0; i < 100; i++) {
        cin >> a[i];
    }

    int counter = 0;
    map<int, int> freq;
    for (int i = 0; i < 10; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < 100; i++) {
        int tmp = a[i] % 10;
        if (tmp == 0) tmp = 9; // map 0 to 9 for easier counting
        else tmp--; // decrement to make 1-9 map to 0-8

        freq[tmp]++;

        if (freq[tmp] == 9) {
            counter++; // individual BINGO!!!
        }

        cout << "Counter: " << counter << endl;

        if (counter == 9) {
            cout << "freq: " << endl;
            for (auto p : freq) {
                cout << p.first + 1 << ": " << p.second << endl;
            }

            cout << endl;
            cout << tmp << endl;
            break;
        }
    }
    return 0;
}