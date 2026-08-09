#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int mx = -1, mn = inf;
        for (int j = 0; j < x; j++) {
            int a; cin >> a;
            mx = max(mx, a); mn = min(mn, a);
        }
        cout << mn << " " << mx << '\n';
    }
    return 0;
}