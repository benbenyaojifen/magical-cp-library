#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n);
    vector<int> a(n), b(n), c(n);
    for (int i = 0, p = 0; i < n; i++) {
        if (p < 2) {
            c[i] = 2;
        } else if (p < 4) c[i] = 0;
        else c[i] = 1;
        p = (p + 1) % 6;
    }
    bool good = false;
    for (int i = 0, k = 0; i < n; i++, k++) {
        if (k % 2 == 0){
            good = !good;
            b[i] = 1;
        } else {
            good ? b[i] = 0 : b[i] = 2;
        }
    }
    for (int i = 0, cnt = 0; i < n; i++) {
        a[i] = cnt;
        cnt = (cnt + 1) % 3;
    }
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if(c == 'A') v[i] = 0;
        else if (c == 'B') v[i] = 1;
        else v[i] = 2;
    }
    int ac = 0, bc = 0, cc = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == v[i]) ac++;
        if (b[i] == v[i]) bc++;
        if (c[i] == v[i]) cc++;
    }
    vector<string> ans;
    int mx = max({ac, bc, cc});
    if(ac == mx) ans.push_back("Adrian");
    if(bc == mx) ans.push_back("Bruno");
    if(cc == mx) ans.push_back("Goran");
    cout << mx << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}