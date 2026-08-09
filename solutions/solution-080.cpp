#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] < b[i]) ans += a[i];
        else {
            ans += b[i];
            cnt++;
        }
    }
    if (cnt & 1) {
        int mn = inf;
        for (int i = 0; i < n; i++) {
            mn = min(mn, abs(a[i] - b[i]));
        }
        ans += mn;
    }
    cout << ans << '\n';
    return 0;
}