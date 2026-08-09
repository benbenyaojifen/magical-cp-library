#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            int val;
            if(c <= 'Z' && c >= 'A'){
                val = int(c);
            } else {
                val = c - '0';
            }
            v[i][j]= val;
        }
    }
    bool latin = true;
    for(int i = 0; i < n; i++){
        unordered_set<int> vis;
        for(int j = 0; j < n; j++){
            if(vis.count(v[i][j])){
                latin = 0; break;
            }
            vis.insert(v[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        unordered_set<int> vis;
        for(int j = 0; j < n; j++){
            if(vis.count(v[j][i])){
                latin = 0; break;
            }
            vis.insert(v[j][i]);
        }
    }
    if(latin){
        bool reduced = true;
        for(int i = 1; i < n; i++){
            if(v[0][i] < v[0][i - 1]){
                reduced = false; break;
            }
        }
        for(int i = 1; i < n; i++){
            if(v[i][0] < v[i - 1][0]){
                reduced = false; break;
            }
        }
        if(reduced){
            cout << "Reduced" << '\n';
        } else {
            cout << "Latin" << '\n';
        }
    } else {
        cout << "No" << '\n';
    }
    return 0;
}