#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
struct BIT {
    int n;
    vector<ll> bit;
    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void add(int pos, ll val) {
        for (int i = pos; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }
    ll sum(int pos) {
       ll res = 0;
        for (int i = pos; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }
    ll sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
 };
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, q; cin >> n >> q;
    BIT bit(n);
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        bit.add(i, v[i]);
    }
    while (q--) {
        int qry;
        cin >> qry;
        if (qry == 1) {
            int pos; ll val; cin >> pos >> val;
            ll diff = val - v[pos];
            v[pos] = val;
            bit.add(pos, diff);
        } else {
            int l, r; cin >> l >> r;
            cout << bit.sum(l, r) << '\n';
        }
    }
    return 0;
}