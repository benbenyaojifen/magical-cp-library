#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    // z algorithm 
    ios::sync_with_stdio(0); cin.tie(0);
    string s, a; cin >> s >> a;
    string t = a + "#" + s;
    vector<int> z(t.size());
    int l = 0, r = 0;
    for (int i = 1; i < t.size(); i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < t.size() && t[z[i]] == t[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = a.size() + 1; i < t.size(); i++) {
        if (z[i] >= a.size()) {
            cout << i - a.size() - 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}