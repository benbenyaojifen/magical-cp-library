#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s; cin >> s;
    ll l = 0, lo = 0, lov = 0, love = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == 'l') l++;
        if (c == 'o') lo += l;
        if (c == 'v') lov += lo;
        if (c == 'e') love += lov;
    }
    cout << love << '\n';
    return 0;
}