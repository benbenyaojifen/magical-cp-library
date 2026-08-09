#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() || v[i] > ans.back()) {
            ans.push_back(v[i]);
        } else {
            int pos = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            ans[pos] = v[i];
        }
    }
    cout << ans.size() << '\n';
    return 0;
}