#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string s; cin >> s;
    int mx = 1e6;
    auto happy = [&] (string ss) {
        int cnt = 0;
        for (int i = 0; i < ss.size(); i++) {
            int c  = ss[i] - '0';
            cnt += c * c;
        }
        
        return to_string(cnt);
    };
    while (mx--) {
        if (stoi(s) == 1) {
            cout << "Yes" << '\n';
            return 0;
        }
        s = happy(s);
    }
    cout << "No" << '\n';
    return 0;
}