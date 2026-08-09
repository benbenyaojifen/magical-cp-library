#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
#define int long long
struct Node {
    ll xr;
};
int N;
vector<Node> seg;
vector<ll> A;

Node mergeNode(const Node &L, const Node &R) {
    Node res;
    res.xr = L.xr ^ R.xr;
    return res;
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx].xr = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
}

void update(int idx, int l, int r, int pos, ll val) {
    if (l == r) {
        seg[idx].xr = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(idx << 1, l, mid, pos, val);
    else update(idx << 1 | 1, mid + 1, r, pos, val);
    seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
}

int queryAbove(int pos) {
    int idx = 1, l = 0, r = N - 1;
    int res = 0;

    while (l < r) {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            int leftX = seg[idx << 1].xr;
            int rightX = seg[idx << 1 | 1].xr;
            if (rightX > leftX) {
                res += (r - mid);
            }
            idx = idx << 1;
            r = mid;
        } else {
            int leftX = seg[idx << 1].xr;
            int rightX = seg[idx << 1 | 1].xr;
            if (leftX >= rightX) {
                res += (mid - l + 1);
            }
            idx = idx << 1 | 1;
            l = mid + 1;
        }
    }
    return res;
}
void solve() {
    int n, q;
    cin >> n >> q;
    N = 1 << n;

    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    seg.assign(4 * N, {0});
    build(1, 0, N - 1);

    while (q--) {
        int b;
        int c;
        cin >> b >> c;
        --b;

        int old = A[b];
        A[b] = c;
        update(1, 0, N - 1, b, c);

        cout << queryAbove(b) << '\n';

        A[b] = old;
        update(1, 0, N - 1, b, old);
    }
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
         solve();
    }
    return 0;
}