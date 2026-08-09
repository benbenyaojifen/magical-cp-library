#include <bits/stdc++.h>

using namespace std;

int main(){
    ios:: sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    long long ans = k + 1; // for the first day
    for(int i = 1; i < n; i++){
        long long gap = vec[i] - vec[i - 1];
        ans += min(gap, (long long) k + 1);
    }
    cout << ans << '\n';
    return 0;
}