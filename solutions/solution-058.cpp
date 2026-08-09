#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for(int i = 0; i < v.size(); i++){
        int x = v[i], y = m - v[i];
        int cnt = upper_bound(v.begin() + i + 1, v.end(), y) - (v.begin() + i + 1);
        ans += cnt;
    }
    cout << ans << '\n';
    return 0;
}