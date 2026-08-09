#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, j;
    cin >> n >> m >> j;
    vector<int> dry(n + 2, INF);
    dry[0] = dry[n + 1] = 0; 
    for (int i = 0; i < m; i++){
        int p, t; cin >> p >> t;
        dry[p] = t;
    }
    vector<int> v(n + 2, INF);
    v[0] = 0;
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i <= n + 1; i++){
        while (!dq.empty() && dq.front() < i - j) dq.pop_front();
        if (dry[i] == INF || dq.empty()){
            v[i] = INF;
        }else {
            int best = v[dq.front()];
            if (best == INF) v[i] = INF;
            else v[i] = max(best, dry[i]);
        }
        if (v[i] != INF) {
            while (!dq.empty() && v[dq.back()] >= v[i]) dq.pop_back();
            dq.push_back(i);
        }
    }
        if (v[n + 1] == INF) cout << -1 << '\n';
        else cout << v[n + 1] << '\n';
        return 0;
}