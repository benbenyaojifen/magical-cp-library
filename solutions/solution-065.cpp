#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; string s; cin >> n >> s;
    //notice that if it is possilbe we can always do it in 1 or 2 steps
    if (n & 1) {
        cout << -1 << '\n';
        return;
    }
    // partition in half
    if (s.substr(0, 3 * n / 2) == s.substr(3 * n / 2)) {
        cout << 1 << '\n';
        for (int i = 0; i < 3 * n; i++) {
            cout << 1 << " \n"[i == 3 * n - 1];
        }
        return;
    }
    vector<int> ans(3 * n, 2);
    for (int i = 0; i < n / 2; i++) {
        int l = 3 * i, r = 3 * n / 2 + 3 * i;
        string a = s.substr(l, 3), b = s.substr(r, 3);
        if (a == b) {
            for (int j = 0; j < 3; j++) {
                ans[l + j] = 1;
                ans[r + j] = 1;
            }
        } else {
            bool done = false;
            for (int j = 0; j < 3 && !done; j++) {
                for (int k = j + 1; k < 3 && !done; k++) {
                    string t = "";
                    t += a[j]; t += a[k];
                    int p = 0;
                    for (char c : b) {
                        if (p < 2 && c == t[p]) p++;
                    }
                    if (p == 2) {
                        ans[l + j] = ans[l + k] = 1;
                        for (int x = 0; x < 3; x++) {
                            if (b[x] == t[0] || b[x] == t[1]) {
                                ans[r + x] = 1;
                            }
                        }
                        done = 1;
                    }
                }
            }
        }
    }
    cout << 2 << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] <<  " \n"[i == ans.size() - 1];
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, k; cin >> t >> k;
    while (t--) {
        solve();
    }
}