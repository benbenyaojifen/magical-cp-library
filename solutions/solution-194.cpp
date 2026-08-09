#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1LL << 60; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    set<pair<int, int>> s;
    int m; cin >> m;
    set<pair<int, int>> vis;
    pair<int, int> cur = {200000, 200000};
    vis.insert({cur.first, cur.second});
    int cnt = 0;
    for (int j = 0; j < m; j++) {
        char c; int x; cin >> c >> x;
        if (c == 'N') {
            for (int i = cur.second + 1; i <= cur.second + x; i++) {
                if (vis.count(make_pair(cur.first, i))) cnt++;
                vis.insert({cur.first, i});
            }
            cur = make_pair(cur.first, cur.second + x);
        } else if (c == 'S') {
            for (int i = cur.second - 1; i >= cur.second - x; i--) {
                if (vis.count(make_pair(cur.first, i))) cnt++;
                vis.insert({cur.first, i});
            }
            cur = make_pair(cur.first, cur.second - x);
        } else if (c == 'E') {
            for (int i = cur.first + 1; i <= cur.first + x; i++) {
                if (vis.count(make_pair(i, cur.second))) cnt++;
                vis.insert({i, cur.second});
            }
            cur = make_pair(cur.first + x, cur.second);
        } else {
            for (int i = cur.first - 1; i >= cur.first - x; i--) {
                if (vis.count(make_pair(i, cur.second))) cnt++;
                vis.insert({i, cur.second});
            }
            cur = make_pair(cur.first - x, cur.second);
        }
    }
    cout << cnt << '\n';
    return 0;
}