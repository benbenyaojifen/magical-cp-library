#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s;
    getline(cin, s);
    cout << "Ready" << '\n';
    while (1) {
        if (s == "  ") break;
        char c = tolower(s[0]), cc = tolower(s[1]);
        string k = ""; k += c; k += cc;
        if (k == "pq" || k == "qp" || k == "db" || k == "bd") {
            cout << "Mirrored pair" << '\n';
        } else {
            cout << "Ordinary pair" << '\n';
        }
        getline(cin, s);
    }
    return 0;
}