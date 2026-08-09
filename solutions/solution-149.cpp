#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<bool> empty(n + 1, false);
    for(int i = 0, x; i < k; i++){
        cin >> x;
        empty[x] = true;

    }
    vector<int> st(n + 1);
    for(int i = 1, x; i <= k + 1; i++){
        cin >> x;
        st[x] = i;
    }
    stack<int> stk;
    int emp = k, cur = 1;
    while(emp){
        if(st[cur]){
            stk.push(st[cur]);
            st[cur] = 0;
        }
        if(empty[cur] && !stk.empty()){
            empty[cur] = false;
            stk.pop();
            emp--;
        }
        cur = cur % n + 1;
    }
    cout << stk.top() << '\n';
    return 0;
}
