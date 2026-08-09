#include <bits/stdc++.h>

using namespace std;

#define int long long

int find(int e){
    int low = 0, high = 1e10; 
    while (low < high){
        int mid = low + (high - low) / 2;
        if (mid * (mid - 1) / 2 >= e) high = mid;
        else low = mid + 1;
    }
    return low;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        cout << find(m) << '\n';
    }
    return 0;
}
