#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int h, w; cin >> h >> w;
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, v; cin >> x >> v;
        if (x == 1) {
            cout << v * w << '\n';
            h -= v;
        } else {
            cout << v * h << '\n';
            w -= v;
        }
    }
    return 0;
}