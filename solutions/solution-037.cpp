#include <bits/stdc++.h>

using namespace std;

void print(const vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    print(v);
    for(int i = 0; i < v.size(); i++){
        bool good = false;
        for(int j = 0; j < v.size() - i - 1; j++){
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                print(v);
                good = true;
            }
        }
        if(!good) break;
    }
    return 0;
}