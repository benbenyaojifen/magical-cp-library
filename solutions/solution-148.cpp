#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        ll s;
        cin >> n >> s;
        ll sum = n * (n + 1) / 2;
        ll diff = sum - s;
        if(diff < 3 || diff >= 2 * n){
            cout << 0 << '\n';
            continue;
        }
        ll low = max(1LL, diff - n);
        ll high = (diff - 1) / 2;
        cout << high - low + 1 << '\n';
    }
    return 0;
}