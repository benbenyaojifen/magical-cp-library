#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    if (m > n + 1) {
        cout << -1 << '\n';
        return 0;
    }
    const int mod = n + m + 1;
    int x = 1;
    for (int i = 0; i < n; i++) {
        int a = ++x, b = ++x;
        a %= mod; b %= mod;
        if (a == 0) a += 2;
        if (a == 1) a++;
        if (b == 0) b += 3;
        if (b == 1) b++;
        if (a == b) a++;
        if (a == i + 1) a++;
        if (b == i + 1) b++;
        cout << a << " " << b << '\n';
    }
    return 0;
}