#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1LL << 60; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    if (n == 2) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s += x;
        }
        cout << (s & 1 ? 1 : 2) << '\n';
    } else {
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 1; i < n - 1; i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < v.size()) {
                ll s = v[l] + v[r];
                ll mid = 2LL * v[i];
                if (s == mid) {
                    cout << 3 << '\n';
                    return 0;
                } else if (s < mid) {
                    r++;
                } else {
                    l--;
                }
            }
        }
        cout << 2 << '\n';
    }
    return 0;
}