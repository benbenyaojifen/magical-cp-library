#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int end = -1;
    for (int i = 0; i < n; i++) {
        if (p[i] != n - i) {
            end = i; break;
        }
    }
    if (end == -1) {
        for (int i = 0; i < n; i++) {
            cout << n - i << " \n"[i == n - 1];
        }
        return;
    }
    int start = find(p.begin(), p.end(), n - end) - p.begin();
    for (int i = 0; i < end; i++) {
        cout << p[i] << " ";
    }
    for (int i = start; i >= end; i--) {
        cout << p[i] << " ";
    }
    for (int i = start + 1; i < n; i++) {
        cout << p[i] << " ";
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