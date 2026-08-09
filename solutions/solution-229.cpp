#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int high0 = 0, high1 = 0, high2 = 0;
    int highest0 = 0, highest1 = 0, highest2 = 0;
    vector<int> ans;
    for(int i = 0; i < v.size() - 1; i++){
        if(i % 3 == 0) high0 -= v[i + 1] - v[i];
        if(i % 3 == 1) high1 -= v[i + 1] - v[i];
        if(i % 3 == 2) high2 -= v[i + 1] - v[i];
        highest0 = max(highest0, high0);
        highest1 = max(highest1, high1);
        highest2 = max(highest2, high2);
    }
    if(highest0 + highest1 + highest2 > v[0]){
        cout << "No" << '\n';
        return 0;
    }
    ans.push_back(highest0);
    ans.push_back(highest1);
    ans.push_back(v[0] - highest0 - highest1);
    for(int i = 3; i < n + 2; i++){
        ans.push_back(ans[i - 3] + v[i - 2] - v[i - 3]);
    }
    cout << "Yes" << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << (i == ans.size() - 1  ? "\n" : " ");
    }
    return 0;
}