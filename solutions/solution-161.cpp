#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    vector<int> diff(n + 1);
    for (int i = 1; i <= n; i++) {
        if (pos[i] != i) {
            int l = min(i, pos[i]), r = max(i, pos[i]);
            diff[l]++;
            diff[r + 1]--;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        if (diff[i] > 0) ans++;
    }
    cout << ans << '\n';
    return 0;
}