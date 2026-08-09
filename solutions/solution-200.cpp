#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y; cin >> x >> y;
        if (x == 1 || (y == 1 && x < 7)) cout << "bad" << '\n';
        else cout << (x >= 4 || y >= 4 ? "good" : "bad") << '\n';
    }
    return 0;
}