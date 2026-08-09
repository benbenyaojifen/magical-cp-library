#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x & 1) odd++;
    }
    if (n % 2 == 0 && odd > n / 2) cout << "Todd" << '\n';
    else cout << "Steven" << '\n';
    return 0;
}