#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    unordered_map<string, int> pass;
    while(q--){
        int ins;
        cin >> ins;
        string s;
        cin >> s;
        if(ins == 1){
            unordered_set<string> st;
            for(int i = 0; i < s.size(); i++){
                for(int j = i; j < s.size(); j++){
                    string temp = "";
                    for(int k = i; k <= j; k++){
                        temp += s[k];
                    }
                    st.insert(temp);
                }
            }
            for(string cur : st){
                pass[cur]++;
            }
        } else {
            cout << pass[s] << '\n';
        }
    }
    return 0;
}