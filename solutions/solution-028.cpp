#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e17;
void solve1() {
    int n, l, q; cin >> n >> l >> q;
    vector<int> diff(n + 2);
    for (int i = 0; i < l; i++) {
        int a, b; cin >> a >> b;
        diff[max(1, a - b)]++;
        diff[min(n + 1, a + b + 1)]--;
    }
    for (int i = 1; i <= n; i++) diff[i] += diff[i - 1];
    for (int i  = 0; i < q; i++) {
        int x; cin >> x;
        cout << (diff[x] ? "Y": "N") << '\n';
    }
}
void solve2() {
    int n, l, q; cin >> n >> l >> q;
    vector<pair<int, int>> seg;
    for (int i = 0; i < l; i++) {
        int a, b; cin >> a >> b;
        seg.emplace_back(max(1, a - b), min(n, a + b));
    }
    sort(seg.begin(), seg.end());
    vector<pair<int, int>> ss;
    for (int i = 0, j = 0; i < seg.size(); i++) {
        auto[a, b] = seg[i];
        j = i + 1;
        while (j < seg.size() && seg[j].first <= b) {
            b = max(b, seg[j].second);
            j++;
        }
        i = j - 1;
        ss.emplace_back(a, b);
    }
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        pair p = {x, inf};
        int pos = upper_bound(ss.begin(), ss.end(), p) - ss.begin();
        pos = max(0, pos - 1);
        auto[a, b] = ss[pos];
        if (x >= a && x <= b) {
            cout << "Y" << '\n';
        } else {
            cout << "N" << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve1();
    return 0;
}