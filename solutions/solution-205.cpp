#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
const int MM = 1e5 + 5;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<bool> prime(MM, true);
    for (int i = 2; i * i <= MM; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MM; j += i) prime[j] = 0;
        }
    }
    vector<int> psa(MM);
    for (int i = 2; i < psa.size(); i++) {
        psa[i] = (prime[i] ? psa[i - 1] + i : psa[i - 1]);
    }
    int t = 5;
    while (t--) {
        int n; cin >> n;
        cout << psa[n] << '\n';
    }
    return 0;
}