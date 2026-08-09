#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= floor(sqrt(n)); i++) {
        ll x2 = 1LL * i * i;
        int remain = n - x2;
        if (remain < 0) continue;
        int my = floor(sqrt(remain));
        if (my < i) continue;
        for (int j = i + 1; j <= my; j++) {
            ll y2 = 1LL * j * j;
            cnt[y2 + x2]++;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}