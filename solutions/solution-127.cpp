#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    getline(cin, s);
    vector<vector<int>> f(26, vector<int>(s.size() + 1));
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == ' ') continue;
        int pos = c - 'a';
        f[pos][i + 1]++;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 1; j < f[i].size(); j++){
            f[i][j] += f[i][j - 1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        char c; cin >> c;
        int pos = c - 'a';
        int ans = f[pos][y] - f[pos][x - 1];
        cout << ans << '\n';
    }
    return 0;
}