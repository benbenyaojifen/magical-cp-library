#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> diff(n);
    diff[0] = v[0];
    for(int i = 1; i < v.size(); i++){
        diff[i] = v[i] - v[i - 1];
    }
    int ans = abs(diff[0]);
    for(int i = 1; i < diff.size(); i++){
        ans += abs(diff[i] - diff[i - 1]);
    }
    cout << ans << '\n';
    return 0;
}