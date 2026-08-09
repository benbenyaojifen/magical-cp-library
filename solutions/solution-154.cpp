#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1LL << 60; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    vector<int> a(5);
    for (int i = 0; i < 5; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i < 4; i++) ans += a[i];
    int d; cin >> d;
    cout << ans * d << '\n';
    return 0;
}