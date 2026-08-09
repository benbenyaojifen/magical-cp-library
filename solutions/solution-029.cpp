#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int left = n - 1, right = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            left = min(left, i);
            right = max(right, i);
        }
    }
    if (right == 0) {
        cout << "Alice" << '\n';
        return;
    }
    bool good = false;

    for (int i = 0; i < left; i++)
        if (v[i] == 1) good = true;

    for (int i = right + 1; i < n; i++)
        if (v[i] == 1) good = true;

    if (good) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}