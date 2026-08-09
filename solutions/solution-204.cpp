#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s, ss; cin >> s >> ss;
    int ans = 0;
    // for (int i = 0; i < min(s.size(), ss.size()); i++) {
    //     if (s.substr(s.size() - i - 1, i + 1) == ss.substr(0, i + 1) || ss.substr(ss.size() - i - 1, i + 1) == s.substr(0, i + 1)) ans = max(ans, i + 1);
    // }
    auto prefix_function = [&] (string a) {
        vector<int> pi(a.size());
        for (int i = 1; i < a.size(); i++) {
            int j = pi[i-1];
            while (j > 0 && a[i] != a[j]) {
                j = pi[j-1];
            }
            if (a[i] == a[j]) j++;
            pi[i] = j;
        }
        return pi;
    };
    vector<int> pi = prefix_function(s + "#" + ss);
    ans = max(ans, pi.back());
    pi = prefix_function(ss + "#" + s);
    ans = max(ans, pi.back());
    cout << ans << '\n';
    return 0;
}