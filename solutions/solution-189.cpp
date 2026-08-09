#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (find(v.begin(), v.end(), 67) != v.end()) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}