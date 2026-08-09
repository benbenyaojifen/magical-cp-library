#include <bits/stdc++.h>
using namespace std;
#define int long long
using i128 = __int128_t;
void solve() {
    int a, b, ca, cb, k; cin >> a >> b >> ca >> cb >> k;
    auto good = [&] (int x) {
        if ((i128) a + ((i128) b + x) / cb * ca < (i128) k) return false;
        // how many use of change chip
        int begin = b / cb, end = (b + x) / cb;
        if (begin < end) {
            int last;
            if (ca >= cb) last = begin;
            else last = end - 1;
            // how many to give to achieve the worst distribution possible
            int worst = last * cb + cb - 1 - b;
            if (worst >= 0 && worst <= x) {
                if ((i128)a + x - worst + ((i128) b + worst) / cb * ca < (i128) k) return false;
            }
        }
        return true;
    };
    int lo = 0, hi = 1000000000000000000;
    // how much we give to b because minima always occur at give all to be or 1 before the multiple of cb
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (good(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}