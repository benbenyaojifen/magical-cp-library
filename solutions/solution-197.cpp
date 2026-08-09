#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
int n, m, a[MM];
bool check(ll lmt){
    ll sum = 0; int cnt = 1;
    for(int i = 1; i <= n; i++){
        if(sum + a[i] > lmt){
            sum = a[i]; cnt++;
        } else {
            sum += a[i];
        }
    }
    return cnt <= m;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    ll lo = 0, hi = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; lo = max((ll)a[i], lo); hi += a[i];
    }
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}