#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
bool p(string &a){
    for (int i = 0; i < a.size() / 2; i++) {
        if(a[i] != a[a.size() - 1 - i]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s; cin >> s;
    for (int i = 1; i < s.size(); i++) {
        string a = s.substr(0, i);
        string b = s.substr(i, s.size() - i);
        if(a.size() && b.size() && p(a) && p(b)){
            cout << "YES" << '\n';
            exit(0);
        }
    }
    cout << "NO" << '\n';
    return 0;
}