#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, k; cin >> n >> k;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = 0;
    bool flg = 1;
    for (int i = 0; i < n - 1 && flg; i++) {
        char c = v[i];
        if (c == 'P' || c == 'S') cnt++;
        if ((c == 'P' && v[i + 1] == 'P') || cnt > k) {
            flg = 0;
            break;
        }
        if (c == 'F') cnt = 0;
    }
    if ((v[n - 1] == 'S' || v[n - 1] == 'P') && cnt + 1 > k) {
        flg = 0;
    }
    if (flg) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 'S') ans++;
            else if (v[i] == 'P') ans += 2;
        }
        cout << "YES" << '\n';
        cout << ans << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}