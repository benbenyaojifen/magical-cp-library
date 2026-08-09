#include <bits/stdc++.h>
using namespace std;
int I, N, J, cnt = 0;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> I >> N >> J;
    vector<int> v(I + 1), psa(I + 1);
    for(int i = 0; i < J; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[x] += z; v[y + 1] -= z;
    }
    for(int i = 1; i < v.size(); i++){
        psa[i] = psa[i - 1] + v[i];
        if(psa[i] >= N) cnt++;
    }
    cout << I - cnt << '\n';
    return 0;
}