#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n, 1);
    long long neg = 1LL * n * (n + 1) / 4;
    for(int i = 0; i < n; i++){
        if(neg >= n - i){
            v[i] = -(n - i);
            neg -= (n - i);
        } else {
            v[i] = -neg;
            break;
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }
    return 0;
}