#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    unordered_map<int, vector<pair<int,char>>> rows;
    int r = 0, c = 0;
    int minR = 0, maxR = 0, maxC = 0;
    auto add = [&](int row, int col, char ch){
        rows[row].push_back({col, ch});
        maxC = max(maxC, col);
    };
    for(char p : s) {
        if(p == '^'){
            add(r, c, '/');    
            c++; r--;      
        } else if(p == 'v'){
            r++;            
            add(r, c, '\\');   
            c++;              
        } else {        
            add(r, c, '_');
            c++;
        }
        minR = min(minR, r);
        maxR = max(maxR, r);
    }
    for (int row = minR; row <= maxR; row++){
        auto &vec = rows[row];
        if (vec.empty()) continue;
        string line;
        int cur = 0;
        for (auto [col, ch] : vec){
            line.append(col - cur, '.');
            line.push_back(ch);
            cur = col + 1;
        }
        line.append(n - line.size(), '.'); 
        cout << line << '\n';
    }
    
    return 0;
}
