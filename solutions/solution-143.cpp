#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string ans = "";
    vector<char> chars;
    for (int i = 'a'; i <= 'z'; i++) chars.push_back((char) i);
    for (int i = 'A'; i <= 'Z'; i++) chars.push_back((char) i);
    for (int i = 0; i <= 9; i++) chars.push_back(i + '0');
    auto qry = [&](const string &s) {
        cout << s << endl;
        int n; cin >> n;
        return n;
    };
    for (int i = 0; i < chars.size(); i++) {
        if (qry(chars[i] + "") == 1) {
            ans += chars[i];
            break;
        }
    }
    while (1) {
        string cur = ans;
        bool ok = 0;
        for (int i = 0; i < chars.size(); i++) {
            int res = qry(cur + chars[i]);
            if (res == -1) return 0;
            if (res == cur.size() + 1) {
                ans += chars[i];
                ok = 1;
                break;
            }
        }
        if (!ok) break;
    }
    while (1) {
        string cur = ans;
        bool ok = 0;
        for (int i = 0; i < chars.size(); i++) {
            int res = qry(chars[i] + cur);
            if (res == -1) return 0;
            if (res == cur.size() + 1) {
                ans = chars[i] + ans;
                ok = 1;
                break;
            }
        }
        if (!ok) break;
    }
    return 0;
}