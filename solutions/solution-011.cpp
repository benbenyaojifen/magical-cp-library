#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s; cin >> s;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++) {
        if (ans.empty() || s[i] - 'a'> ans.back()) {
            ans.push_back(s[i] - 'a');
        } else {
            int pos = lower_bound(ans.begin(), ans.end(), s[i] - 'a') - ans.begin();
            ans[pos] = s[i] - 'a';
        }
    }
    cout << 26 - ans.size() << '\n';
    return 0;
}