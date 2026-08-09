#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, r; cin >> n >> r;
    map<int, int> p;
    p[r] = 0;
    for (int i = 1; i < n; i++) {
        cin >> r;
        auto it = p.lower_bound(r);
        if (it == p.begin()) {
            cout << "NO" << '\n';
            return 0;
        }
        --it;
        p[r] = 0;
        p[it->first]++;
        if (p[it->first] == 2) p.erase(it);
    }
    cout << "YES" << '\n';
    return 0;
}