#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << i << " \n"[i == n];
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}