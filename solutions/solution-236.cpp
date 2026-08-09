#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    if (n == 2 || n & 1) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    return 0;
}