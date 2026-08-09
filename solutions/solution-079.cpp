#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n);
    unordered_map<int, int> f;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (!f.count(v[i] + v[j])) f[v[i] + v[j]] = i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int cur = v[i] - v[j];
            if (f.count(cur) && f[cur] < i) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}