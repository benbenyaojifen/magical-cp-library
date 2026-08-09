#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<ll> wt(n), val(n);
    for(int i = 0; i < n; i++){
        cin >> wt[i]; cin >> val[i];
    }
    vector<vector<ll>> dp(wt.size() + 1, vector<ll>(w + 1));
    for(int i = 0; i <= wt.size(); i++){
        for(int j = 0; j <= w; j++){
            if(j == 0 || i == 0) dp[i][j] = 0;
            else {
                ll pick = 0;
                if(wt[i - 1] <= j){
                    pick = max(dp[i][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
                }
                ll not_pick = dp[i - 1][j];
                dp[i][j] = max(pick, not_pick);
            }
        }
    }
    cout << dp[wt.size()][w] << '\n';
}