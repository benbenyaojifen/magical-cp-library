#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        vector<char> x(n), y(n);
        for (int i = n - 1; i >= 0; i--) cin >> x[i];
        for (int i = n - 1; i >= 0; i--) cin >> y[i];
        for (int i = 0; i < n; i++) {
            cout << y[i] << x[i];
        }
        cout << '\n';
    }
    return 0;
}