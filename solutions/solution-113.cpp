#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
const int mod = 1e9 + 7;
void solve() {
    int n; cin >> n;
    vector<int> lft(n + 1), rit(n + 1), par(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> lft[i] >> rit[i];
        if (lft[i] != 0) par[lft[i]] = i;
        if (rit[i] != 0) par[rit[i]] = i;
    }
    par[1] = 0;
    vector<int> order;
    stack<int> stk;
    stk.push(1);
    while (!stk.empty()) {
        int v = stk.top(); stk.pop();
        order.push_back(v);
        if (lft[v] != 0) stk.push(lft[v]);
        if (rit[v] != 0) stk.push(rit[v]);
    }
    vector<ll> par_cost(n + 1);
    for (int i = order.size() - 1; i >= 0; i--) {
       if (lft[order[i]] == 0 && rit[order[i]] == 0) {
        par_cost[order[i]] = 1;
        } else {
        par_cost[order[i]] = (par_cost[lft[order[i]]] + par_cost[rit[order[i]]] + 3) % mod;
        }
    }
       vector<ll> root_cost(n + 1);
       root_cost[1] = par_cost[1];
       stk.push(1);
       while (!stk.empty()) {
        int v = stk.top(); stk.pop();
        if (lft[v] != 0) {
            root_cost[lft[v]] = (root_cost[v] + par_cost[lft[v]]) % mod;
            stk.push(lft[v]);
        }
        if (rit[v] != 0) {
            root_cost[rit[v]] = (root_cost[v] + par_cost[rit[v]]) % mod;
            stk.push(rit[v]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << root_cost[i] << " \n"[i == n];
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}