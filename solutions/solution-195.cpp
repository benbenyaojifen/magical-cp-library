#include <bits/stdc++.h>
using namespace std;
bool good(long long d, int n, vector<pair<long long, long long>>& seg){
    long long cows = 0;
        long long last = 0;
        bool has_last = 0;
        for (auto &p : seg) {
            long long a = p.first, b = p.second;
            long long start;
            if (!has_last) {
                start = a;
            } else {
                start = max(a, last + d);
            }
            if (start > b) continue;
            long long diff = b - start;
            long long cnt = 1 + diff / d;
            cows += cnt;
            if (cows >= n) return true;
            long long new_last = start + (cnt - 1) * d;
            last = new_last;
            has_last = true;
        }
        return cows >= n;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<long long, long long>> seg(m);
    for (int i = 0; i < m; i++) {
        long long a, b; cin >> a >> b;
        seg[i] = {a, b};
    }
    sort(seg.begin(), seg.end());
    long long lo = 1;
    long long hi = 1e18;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if (good(mid, n, seg)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}
