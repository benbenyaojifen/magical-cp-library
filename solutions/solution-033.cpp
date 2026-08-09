#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    int mx = 0, ans = -1;
    for (auto[x, y] : freq) {
        if (x * y > mx) {
            mx = x * y;
            ans = x;
        }
    }
    cout << ans << '\n';
    return 0;
}