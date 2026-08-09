#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    int n; cin >> n;
    n *= 3;
    vector<int> v;
    bool f = 1, s = 1;
    int cur = 1;
    int a = n;
    for (int i = 1; i <= n; i++) {
        if (f) {
            cout << cur << " ";
            f = 0;
            s = 1;
            cur++;
        } else {
            if (s) {
                cout << a-- << " ";
                s = 0;
            } else {
                cout << a-- << " ";
                f = 1;
            }
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}