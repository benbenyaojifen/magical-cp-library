#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[5001], r[5001], psa[5001 * 2];
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){int a, b; cin >> a >> b; l[a]++; r[b]++;}
    int k = 2 * m;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m; j++){
            psa[i + j] += l[i] * l[j];
            psa[i + j + 1] -= r[i] * r[j];
        } 
    }
    cout << psa[0] << '\n';
    for(int i = 1; i <= k; i++){
        psa[i] = psa[i] + psa[i - 1];
        cout << psa[i] << '\n';
    }
    return 0;
}