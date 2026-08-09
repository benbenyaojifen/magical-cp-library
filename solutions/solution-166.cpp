#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s; int n; cin >> s >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; string v; cin >> x >> v;
        if (v == s) ans = max(ans, x);
        else if (v == "GRASS" && s == "FIRE") ans = max(ans, x / 2);
        else if (v == "GRASS" && s == "WATER") ans = max(ans, 2 * x);
        else if (v == "FIRE" && s == "WATER") ans = max(ans, x / 2); 
        else if (v == "FIRE" && s == "GRASS") ans = max(ans, x * 2); 
        else if (v == "WATER" && s == "GRASS") ans = max(ans, x / 2);
        else if (v == "WATER" && s == "FIRE") ans = max(ans, x * 2);
    }
    cout << ans << '\n';
    return 0;
}