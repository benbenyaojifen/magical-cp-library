#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    // int len = r - l;
    ll cnt = 0;
    // for (int i = 0; i < s.size(); i++) {
    //     char c = s[i];
    //     for (int j = min(n - 1, i + l); j <= min(n - 1, j + r); j++) {
    //         if (j >= i + l && j <= i + r && s[j] == c) {
    //             cnt++;
    //         }
    //     }
    // }
    vector<vector<int>> psa(26, vector<int>(n));
    psa[s[0] - 'a'][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            psa[j][i] = psa[j][i - 1];
        }
        psa[s[i] - 'a'][i]++;
    }
    for (int i = 0; i < n; i++) {
        int lft = i + l, rit = min(n - 1, i + r);
        if (lft > rit) continue;
        cnt += (lft > 0 ? psa[s[i] - 'a'][rit] - psa[s[i] - 'a'][lft - 1] : psa[s[i] - 'a'][rit]);
    }
    cout << cnt << '\n';
    return 0;
}