#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, g, b;
    cin >> r >> g >> b; // required

    int c_r, c_g, c_b;
    cin >> c_r >> c_g >> c_b; // have

    int c_rg, c_gb;
    cin >> c_rg >> c_gb;

    int result = 0;

    int to_need_red = abs(c_r - r);
    int to_need_green = abs(c_g - g);
    int to_need_blue = abs(c_b - b);

    return result;
}            