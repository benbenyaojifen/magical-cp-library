#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for(int i = 0; i < vec.size(); i++){
        cin >> vec[i];
    }
    set<int> decrease;
    auto down = [&](int i) {
        int nxt = (i + 1) % n;
        return vec[i] > vec[nxt];
    };
    for (int i = 0; i < n; i++) {
        if (down(i)) {
            decrease.insert(i);
        }
    }
    for(int i = 0; i < q; i++){
        int index, x;
        cin >> index >> x;
        index--;
        vec[index] = x;
        for(int j = -1; j <= 0; j++){
            int pos = (index + j + n) % n;
            decrease.erase(pos);
            if(down(pos)) decrease.insert(pos);
        }
        if(decrease.size() > 1){
            cout << -1 << '\n';
        } else if(decrease.empty()){
            cout << 0 << '\n';
        } else {
            int ans = *decrease.begin();
            cout << min(ans + 1, n - ans - 1) << '\n';
        }
    }
    return 0;
}