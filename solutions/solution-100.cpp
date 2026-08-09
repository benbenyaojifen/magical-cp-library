#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string n; cin >> n;
    string s = "GOAMPLITUDE";
    int indx = 0;
    for (char c : n) {
        indx = (indx * 10 + (c - '0')) % 11;
    }
    cout << s[indx >= 1 ? indx - 1 : 10] << '\n';
    return 0;
}