#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int m, s, t; cin >> m >> s >> t;
    int run = 0, jump = 0;
    for (int i  = 1; i <= t; i++) {
        run += 17;
        if(m >= 10) {
            jump += 60;
            m -= 10;
        } else {
            m += 4;
        }
        run = max(run, jump);
        if (run >= s) {
            cout << "Yes" << '\n';
            cout << i << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    cout << run << '\n';
    return 0;
}