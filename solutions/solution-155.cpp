#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<string, vector<pair<int, int>>> pos;
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            for(int j = 0; j < m; j++){
                string s; int c, v;
                cin >> s >> c >> v;
                pos[s].emplace_back(c, v);
            }
        }
        int k;
        cin >> k;
        unordered_map<string, int> need;
        for(int i = 0; i < k; i++){
            string s; int v;
            cin >> s >> v;
            need[s] = v;
        }
        int cost = 0;
        for(auto &[s, v] : pos){
            sort(v.begin(), v.end());
        }
        for(auto[name, amount] : need){
            auto &vec = pos[name];
            for(auto[co, am] : vec){
                if(amount >= am){
                    cost += co * am;
                    amount -= am;
                } else {
                    cost += co * amount;
                    break;
                }
            }
        }
        cout << cost << '\n';
    }
}