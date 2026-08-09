#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, pos; cin >> n >> pos;
    vector<pair<int, int>> a;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int get, cost; cin >> get >> cost;
        if (i + 1 == pos) {
            cur = get;
            continue;
        }
        if (get - cost < 0) continue;
        a.emplace_back(cost, get);
    }
    sort(a.begin(), a.end(), [&] (const pair<int, int> &x, const pair<int, int> &y) {
            if (x.first != y.first) return x.first < y.first;
            return x.second > y.second;
    });
    int cnt = 1;
    for (int i = 0; i < a.size(); i++) {
        if (cur >= a[i].first) {
            cur -= a[i].first;
            cur += a[i].second;
            cnt++;
        } else {
            break;
        }
    }
    cout << cur << '\n';
    cout << cnt << '\n';
    return 0;
}