#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int r, c, m; cin >> r >> c >> m;
    vector<int> odp(c), dp(c);
    for (int i = 0; i < c; i++) {
        odp[i] = i % m + 1;
    }
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int cur = (c * i + j) % m + 1;
            dp[j] = min({odp[j], odp[max(0, j - 1)], odp[min(c - 1, j + 1)]}) + cur;
        }
        swap(dp, odp);
    }
    cout << *min_element(odp.begin(), odp.end()) << '\n';
    return 0;
}