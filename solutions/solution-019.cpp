#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, h;
    cin >> n >> q >> h;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int th, amount;
        cin >> th >> amount;
        if(th > h) amount = 0;
        v[i] = amount;
    }
    vector<int> psa(n + 1);
    psa[0] = 0;
    for(int i = 0; i < v.size(); i++){
        psa[i + 1] = psa[i] + v[i];
    }
    int ans = INT_MIN;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        int res = psa[r + 1] - psa[l];
        ans = max(ans, res);
    }
    cout << ans << '\n';
    return 0;
}