#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int qry(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}
void solve() {
    int n; cin >> n;
    if (qry(1, 2) == 1) {
        cout << "! " << 1 << endl;
        cout.flush();
        return;
    }
    if (qry(2, 3) == 1) {
        cout << "! " << 2 << endl;
        cout.flush();
        return;
    }
    if (qry(1, 3) == 1) {
        cout << "! " << 1 << endl;
        cout.flush();
        return;
    }
    for (int i = 4; i <= 2 * n - 2; i += 2) {
        if (qry(i, i + 1) == 1) {
            cout << "! " << i << endl;
            cout.flush();
            return;
        }
    }
    cout << "! " << 2 * n << endl;
    cout.flush();
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}