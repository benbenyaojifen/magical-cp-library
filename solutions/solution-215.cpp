#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
vector<ll> primes;
vector<bool> isprime(300000, 1);
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << primes[n - 2] << '\n';
            break;
        }
        if (i > 0) {
            cout << primes[i] * primes[i - 1] << " ";
        } else {
            cout << primes[i] << " ";
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    for (int i = 2; i < 300000; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < 300000; j += i) {
                isprime[j] = 0;
            }
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}