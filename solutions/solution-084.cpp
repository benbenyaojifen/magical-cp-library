#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> tar(n + 1), used(n + 1);
    for (int i = 0; i < k; i++) { 
        tar[a[i]]++;
    }
    for (int i = 0; i < k; i++) {
        bool c = 1;
        int f = a[i];
        for (int j = i + k; j < n; j += k) {
            if (a[j] != f) {
                c = 0; 
                break;
            }
        }
        if (!c) {
            for (int j = i; j < n; j += k) {
                if (b[j] != -1 && b[j] != a[j]) {
                    cout << "NO" << '\n';
                    return;
                }
            }
            used[a[i]]++;
        } else {
            int val = -1;
            for (int j = i; j < n; j += k) {
                if (b[j] != -1) {
                    if (val == -1) {
                        val = b[j];
                    } else if (val != b[j]) {
                        cout << "NO" << '\n';
                        return;
                    }
                }
            }
            if (val != -1) {
                used[val]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (used[i] > tar[i]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}