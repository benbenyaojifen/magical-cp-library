#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<char>>& grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
void move_blood(vector<vector<char>>& v){
    //left 
    bool stuck = true;
    while(true){
    stuck = true;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == 'W'){
                while(j > 0 && v[i][j - 1] == '.'){
                   v[i][j - 1] = 'W';
                   v[i][j] = '.';
                   j--;
                   stuck = false;
                }
            }
        }
    }
    //down 
        vector<pair<int,int>> drop;
        for (int i = 0; i < v.size() - 1; i++)
            for (int j = 0; j < v[i].size(); j++)
                if (v[i][j] == 'W' && v[i + 1][j] == '.')
                    drop.push_back({i, j});

        if (!drop.empty()) stuck = false;
        for (auto [i, j] : drop){
            v[i + 1][j] = 'W';
            v[i][j]   = '.';
        }

    if(stuck) break;
}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m;
    vector<vector<char>> pool(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> pool[i][j];
        }
    }
    cin >> q;

    while(q--){
        int op;
        cin >> op;
        if(op == 2){
            print(pool);
        } else {
            //先处理头 out of bound 消失 down 
            //Blood can only move to empty cells 
            //到最左 然后向下 repeat 直到动不了
            for(int i = pool.size() - 1; i >= 0; i--){
                for(int j  = 0; j < pool[i].size(); j++){
                    if(pool[i][j] == 'X' && i == pool.size() - 1){
                        pool[i][j] = '.';
                    } else if(pool[i][j] == 'X'){
                        pool[i + 1][j] = 'X';
                        pool[i][j] = '.';
                    }
                }
            }
            move_blood(pool);
        }
    }
    return 0;
}
