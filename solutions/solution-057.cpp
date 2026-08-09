#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    vector<int> first_occur(n + 1);
    for(int i = 1; i < v.size(); i++){
        int f = v[i];
        if(first_occur[f] == 0){
            first_occur[f] = i;
        }
    }
    vector<int> inv(n + 1);
    for(int i = 1; i < v.size(); i++){
        int d = first_occur[i];
        if(d != 0){
            inv[d] = i;
        }
    }
    vector<int> order;
    for(int i = 1; i <= n; i++){
        if(inv[i] != 0){
            order.push_back(inv[i]);
        }
    }
    //one day is guarded every day
    if(order.size() < 2){
        cout << -1 << '\n';
        exit(0);
    }
    vector<int> ans(n + 1); 
    for(int i = 0; i < order.size(); i++){
        int cur = order[i];
        int prev = order[(i + order.size() - 1) % order.size()];
        int day = first_occur[cur];
        ans[day] = prev;
    }
    vector<bool> used_bank(n + 1), used_day(n + 1);
    for(int bank : order){
        used_bank[bank] = true;
        used_day[first_occur[bank]] = true;
    }
    //assign position for banks that the gaurd never gaurded 
    vector<int> days, banks;
    for(int i = 1; i <= n; i++){
        if(!used_bank[i]) banks.push_back(i);
    }
    for(int i = 1; i <= n; i++){
        if(!used_day[i]) days.push_back(i);
    }
    for(int i = 0; i < days.size(); i++){
        ans[days[i]] = banks[i];
    }   
    for(int i = 1; i < ans.size(); i++){
         cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
    return 0;
}