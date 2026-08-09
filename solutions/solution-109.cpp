#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s; cin >> s;
    string ans = "";
    for (int i = 0, j; i < s.size(); i++, j = i) {
        char c = s[i];
        if (c == '+') { 
            ans += " tighten ";
        } else if (c == '-') {
            ans += " loosen ";
        } else if (isalpha(c)) {
            ans += c;
        } else if (isdigit(c)) {
            while (isdigit(c)) {
                ans += c;
                j++;
                c = s[j];
            }
            i = j - 1;
            cout << ans << '\n';
            ans = "";
        }
    }
    return 0;
}