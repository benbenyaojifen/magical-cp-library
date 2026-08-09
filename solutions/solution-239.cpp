
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    for(int t = 0; t < 5; t++){
        getline(cin, line);
        int cnt = 0, cur = 0;
        for(int i = 0; i < line.size(); i++){
            if(isalpha(line[i])){
                cur++;
            } else {
                if(cur >= 4) cnt++;
                cur = 0;
            } 
        }
    
        cout << (cur >= 4 ? cnt + 1 : cnt) << '\n';
    }
    return 0;
}