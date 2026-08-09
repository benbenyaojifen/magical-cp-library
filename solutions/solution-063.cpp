#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cost;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cost.push_back(x);
    }
    sort(cost.begin(), cost.end());
    int ans = -1;
    int best = 0;
    for(int c : cost){
        int cur = n - (lower_bound(cost.begin(), cost.end(), c) - cost.begin());
        cur *= c;
        if(cur > best){
            best = cur;
            ans = c;
        }
    }
    cout << best << " " << ans << '\n';
    return 0;
}