/*
bruce code
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int N, M, a[MM];  string s; ll ans, loss;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> s;
    for(int i=0; i<N; i++) {
        cin >> a[i]; ans += a[i];
    }
    for(int i=0; i<N; i++) {
        if(s[i] == 'R' && s[(i+1)%N] == 'L') {
            ll sum = 0;
            for(int j=(i-1+N)%N; s[j]=='R'; j=(j-1+N)%N){
                sum += a[j];
            }
            loss += min((ll)M, sum);  sum = 0;
            for(int j=(i+2)%N; s[j]=='L'; j=(j+1)%N){
                sum += a[j];
            }
            loss += min((ll)M, sum);
        }
    }
    cout << ans - loss << "\n";
}*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
int n;
long long m;
long long cap[MAXN];
int indeg[MAXN], nxtCow[MAXN], vis[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s;
    cin >> s;
    s = "a" + s;// 1-index
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cap[i];
        total += cap[i];
    }
    // Build directed graph
    for (int i = 1; i <= n; i++) {
        int j;
        if (s[i] == 'L') {
            j = (i == 1 ? n : i - 1); // wrap around left
        } else {
            j = (i == n ? 1 : i + 1); // wrap around right
        }
        nxtCow[i] = j;
        indeg[j]++;  // j has one more incoming edge
    }

    // Start from all cows with indegree 0 (net givers)
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && indeg[i] == 0) {
            vector<int> path;
            int cur = i;
            // Follow the chain until we reach a visited node(cycle)
            while (!vis[cur]) {
                vis[cur] = 1;
                path.push_back(cur);
                cur = nxtCow[cur];
            }
            // All nodes in path before the first occurrence of cur are non-cycle
            long long nonCycleSum = 0;
            for (int x : path) {
                if (x == cur) break;
                nonCycleSum += cap[x];
            }
            // This chain can lose at most min(m, sum of its non-cycle milk)
            total -= min(m, nonCycleSum);
        }
    }
    cout << total << '\n';
    return 0;
}
