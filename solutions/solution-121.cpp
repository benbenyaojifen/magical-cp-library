#include <bits/stdc++.h>

using namespace std;

//❄️
#define int long long 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
        mx += val[i];
    }
    vector<int> dp(mx + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for(int i = 1; i <= wt.size(); i++){
        for(int j = mx; j >= val[i - 1]; j--){
            dp[j] = min(dp[j], dp[j - val[i - 1]] + wt[i - 1]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= mx; i++){
        if(dp[i] <= w) ans = i;
    }
    cout << ans << '\n';
    return 0;
}