#include <bits/stdc++.h>
using namespace std;

void floyd_cycle(int x, const vector<int> &succ, vector<int> &ans){
    int a = succ[x], b = succ[succ[x]];
    // meet inside the cycle, but bail if we hit a known node
    while (a != b) {
        if (ans[a] || ans[b]) break;              // <<< early exit if chain already solved
        a = succ[a]; b = succ[succ[b]];
    }
    // Only do cycle work if we actually found a *new* cycle
    if (a == b && ans[a] == 0) {                  // <<< skip if cycle already labeled
        // find cycle entry
        a = x;
        while (a != b) { a = succ[a]; b = succ[b]; }
        int entry = a;

        // find cycle length
        int len = 1, nxt = succ[entry];
        while (nxt != entry) { nxt = succ[nxt]; len++; }

        // fill cycle nodes
        int v = entry;
        do { ans[v] = len; v = succ[v]; } while (v != entry);
    }
    // fill tail toward the first known node/cycle
    vector<int> path;
    int v = x;
    while (ans[v] == 0) { path.push_back(v); v = succ[v]; }
    for (int i = (int)path.size() - 1; i >= 0; --i)
        ans[path[i]] = ans[succ[path[i]]] + 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> succ(n + 1), ans(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> succ[i];
    }
    for(int i = 1; i <= n; i++){
        if(ans[i] == 0) floyd_cycle(i, succ, ans);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << (i == n ? "\n" : " ");
    }
    return 0;
}