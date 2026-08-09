#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m;              
    ll k;
    cin >> n >> m >> k;
    m = min(n, m);
    vector<int> ans(n);
    int cur = 1;
    int index = 0;
    bool all = true;
    //first m distinct pitch
    for(int i = 0; i < m; i++){
        // this checks if we can still place it or not since we have to remain the slots for placing one -> each slot must place at least one
        if(n - (i + 1) + i + 1 > k){
            all = false;
            break;
        }
        ans[i] = i + 1;
        index++;
        k -= i + 1;
    } 
    // cout << k << endl;

    //cannot place anything 
    if(index == 0){
        cout << -1 << '\n';
        return 0;
    } 
    //reset to form cycle 
    while(index < n && k > 0){
        // check if we can place the current pitch without going over -(n - index - 1) to account for the ones that we must place at the end
        if(k - m - (n - index - 1) >= 0 && all){
            ans[index] = cur;
            index++;
            cur++;
            if(cur > m) cur = 1;// the ensure it is distinct we do 1 to m repeatedly
            //every time we place a distinct pitch we add m good samples
            k -= m;
            // cout << "run" << '\n';
        } else {
            // we cannot place distinct pitch anymore
            int remain = n - index - 1; // how many ones that we must place at the end 
            int need = k - remain;
            int place = ans[index - need];
            ans[index] = place;
            k -= need;
            index++;
            // cout << remain << " " << need << " " << place << endl;
            break;
        }
        // cout << k << endl;
    }
    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    // }
     //place the ones 
    while(index < n){
        ans[index] = ans[index - 1];
        index++;
        k--;
    }
    // cout << k << endl;
    if(k != 0){
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}