#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1LL << 60; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (v[0] == -1) {
        int k = min(100, n / 4);
        cout << k << '\n';
        int cur = 1;
        for (int i = 0; i < k; i++) {
            cout << 2 << " " << 2 << '\n';
            cout << cur << " " << cur + 1 << '\n';
            cout << cur + 2 << " " << cur + 3 << '\n';
            cur += 4;
        }
        return 0;
    }
    auto out = [&](const vector<int> &a, const vector<int> &b) {
        cout << "YES" << '\n';
        cout << a.size() << " " << b.size() << '\n';
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " \n"[i == a.size() - 1];
        }
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " \n"[i == b.size() - 1];
        }
    };
    if (n < 5) { // 0 --> not used, 1 --> alice, 2 --> bob
        ll lim = 1;
        for (int i = 0; i < n; i++) lim *= 3;
        for (int mask = 0; mask < lim; mask++) {
            ll x = mask;
            vector<int> a, b;
            ll sum_a = 0, sum_b = 0;
            for (int i = 0; i < n; i++) {
                int c = x % 3;
                x /= 3;
                if (c == 1) {
                    a.push_back(i + 1);
                    sum_a += v[i];
                } else if (c == 2) {
                    b.push_back(i + 1);
                    sum_b += v[i];
                }
            }
            if (a.size() == 0 || b.size() == 0 || a.size() == n || b.size() == n) continue;
            int g = gcd(sum_a, sum_b);
            if (g > 1) {
                out(a, b);
                return 0;
            }
        }
        cout << "NO" << '\n';
        return 0;
    }
    vector<int> even_indx, odd_indx;
    for (int i = 0; i < 5; i++) {
        if ((v[i] & 1) == 0) even_indx.push_back(i + 1);
        else odd_indx.push_back(i + 1);
    }
    if (even_indx.size() >= 4) {
        vector<int> a = {even_indx[0], even_indx[1]}, b = {even_indx[2], even_indx[3]};
        out(a, b);
        return 0;
    } else if (odd_indx.size() >= 4) {
        vector<int> a = {odd_indx[0], odd_indx[1]}, b = {odd_indx[2], odd_indx[3]};
        out(a, b);
        return 0;
    } else if (even_indx.size() == 3 && odd_indx.size() == 2) {
        vector<int> a = {even_indx[0], even_indx[1]}, b = {odd_indx[0], odd_indx[1]};
        out(a, b);
        return 0;
    } else if (even_indx.size() == 2 && odd_indx.size() == 3) {
        vector<int> a = {odd_indx[0], odd_indx[1]}, b = {even_indx[0], even_indx[1]};
        out(a, b);
        return 0;
    }
    return 0;
}