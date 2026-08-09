#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s; cin >> s;
    unordered_map<char, int> pos;
    int indx = 1;
    for (int i = 'a'; i <= 'z'; i++) {
        pos[(char)i] = indx;
        indx++;
    }
    vector<int> f(26);
    for (int i = 0; i < s.size(); i++) {
        f[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < f.size(); i++) {
        if (f[i]) {
            ans += pos[(char) (i + 'a')] * f[i];
        }
    }
    cout << ans << '\n';
    return 0;
}