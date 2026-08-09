#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> all(n - 1);
    vector<pair<int, int>> first;
    for(int i = 0; i < n; i++){
        vector<int> v(k);
        for(int j = 0; j < k; j++){
            cin >> v[j];;
        }
        for(int j = 0; j < v.size() - 1; j++){
            for(int m = j + 1; m < v.size(); m++){
                int larger = v[j], smaller = v[m];
                if(i == 0){
                    first.emplace_back(larger, smaller);
                } else {
                    all[i - 1].push_back({larger, smaller});
                }
            }
        }
    }
    int ans = first.size();
    for(auto p1 : first){
        for(int i = 0; i < all.size(); i++){
            if(find(all[i].begin(), all[i].end(), p1) == all[i].end()){
                ans--; break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}   