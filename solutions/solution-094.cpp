#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q = 10;
    while(q--){
        int n, m, d;
        cin >> n >> m >> d;
        int reset = n;
        vector<int> v(d);
        for(int i = 0; i < m; i++){
            int day;
            cin >> day;
            day--;
            v[day]++;
        }
        int ans = 0;
        for(int i = 0; i < d; i++){
            if(n == 0){
                ans++;
                n = reset;
            }
            if(v[i] > 0){
                n += v[i] - 1;
                reset += v[i];
            } else {
                n--;
            }
        }
        cout << ans << '\n';
    }
}