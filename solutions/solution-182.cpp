#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
vector<ll> seg;
void build(const vector<int> &a, int indx, int l, int r) {
    if (l == r) {
        seg[indx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(a, indx * 2, l, mid);
    build(a, indx * 2 + 1, mid + 1, r);
    seg[indx] = seg[indx * 2] + seg[indx * 2 + 1];
}
void update(int pos, int val, int indx, int l, int r) {
    if (l == r) {
        seg[indx] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(pos, val, indx * 2, l, mid);
    } else update(pos, val, indx * 2 + 1, mid + 1, r);
    seg[indx] = seg[indx * 2] + seg[indx * 2 + 1];
}
ll qry(int ql, int qr, int indx, int l, int r) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return seg[indx];
    int mid = (l + r) >> 1;
    return qry(ql, qr, indx * 2, l, mid) + qry(ql, qr, indx * 2 + 1, mid + 1, r);  

}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, q; cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    seg.assign(4 * n, 0);
    build(v, 1, 1, n);
    while (q--) {
        char c;
        int x, y; cin >> c >> x >> y;
        if (c == 'U') update(x, y, 1, 1, n);
        else {
            cout << qry(x, y, 1, 1, n) << " \n"[q > 0];
        }
        
    }
    return 0;
}