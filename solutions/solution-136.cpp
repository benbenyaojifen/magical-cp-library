#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n), a(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (v[0] != a[0] || v[n - 1] != a[n - 1]) {
        cout << "No" << '\n';
        return 0;
    }
    vector<int> diff1, diff2;
    for (int i = 1; i < n ; i++) {
        diff1.push_back( v[i] - v[i - 1]);
        diff2.push_back(a[i] - a[i - 1]);
    }
    sort(diff1.begin(), diff1.end());
    sort(diff2.begin(), diff2.end());
    if (diff1 == diff2) cout << "Yes" << '\n'; 
    else cout << "No" << '\n';
    return 0;
}