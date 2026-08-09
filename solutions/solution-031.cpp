#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mx = 0;
        int add = 2;
        for (int i = 0; i < n - 1; i++) {
            mx += add;
            add += 2;
        }
        //or just use mx = n * (n - 1)
        unordered_map<int, int> cnt;
        bool good = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x; cin >> x;
                cnt[x]++;
                if (cnt[x] > mx) {
                    good = 0;
                }
            }
        }
        if (good) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}