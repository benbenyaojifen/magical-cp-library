#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> next(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i++){
        if(i != n) next[i] = i + 1;
        else next[i] = 0;
        pre[i] = i - 1;
    }
    int head = 1;
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        if(l == r){
            //detatch l
            int x = pre[l], y = next[l];
            if(x) next[x] = y; // set x - 1 = x + 1
            else head = y; 
            if(y) pre[y] = x; 
            //insert
            if(k == 0){ // move to front
                pre[l] = 0;
                next[l]= head;
                if(head) pre[head] = l;
                head = l;
            } else { // after k
                int next_k = next[k];
                next[k] = l;
                pre[l] = k;
                next[l] = next_k;
                if(next_k) pre[next_k] = l;
            }
        } else {
            //detached [l, r]
            int prev_l = pre[l], next_r = next[r];
            if(prev_l) next[prev_l] = next_r;
            else head = next_r;
            if(next_r) pre[next_r] = prev_l;
            //insert
            if(k == 0){
                pre[l] = 0;
                next[r] = head;
                if(head) pre[head] = r;
                head = l;
            } else {
                int next_k = next[k];
                next[k] = l;
                pre[l] = k;
                next[r] = next_k;
                if(next_k) pre[next_k] = r;
            }
        }
    }
    for(int i = head; i; i = next[i]){
        cout << i << (next[i] ? " " : "\n");
    }
    return 0;
}