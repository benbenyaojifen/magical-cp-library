#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1LL << 60; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int a, b, c; cin >> a >> b >> c;
    if (a <= b - c) cout << "Y " << b - c - a << '\n';
    else cout << "N" << '\n';
    return 0;
}