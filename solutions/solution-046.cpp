#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    vector<int> coin;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        coin.push_back(c);
    }
    vector<int> dp(x + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for(int i = 1; i < dp.size(); i++){
        for(int c : coin){
            if(c <= i){
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    cout << dp[x] << '\n';
    return 0;
}