#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++){
        if (deg[i] > mx){
            mx = deg[i];
        }
    }
    cout << mx + 1 << '\n';
    return 0;
}
