#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; long long K;
    cin >> N >> M >> K;
    vector<pair<int,int>> seg(M);
    for(int i = 0; i < M; i++){
        int L, R; cin >> L >> R;
        seg[i] = {L, R};
    }
    // Build pos after one routine, position newPos holds oldPos
    vector<int> pos(N + 1);
    iota(pos.begin(), pos.end(), 0); // pos[i] = i
    for(auto [L, R] : seg){
        for(int i = 0; i < (R - L + 1) / 2; i++){
            swap(pos[L + i], pos[R - i]);
        }
    }
    // Q's perpose is mapping oldPos to newPos after one routine
    vector<int> Q(N + 1);
    for(int newPos = 1; newPos <= N; newPos++){
        int oldPos = pos[newPos];
        Q[oldPos] = newPos;
    }

    // Binary lifting up[i][v] = Q^(2^i)(v)
    const int LOG = 60;
    vector<vector<int>> up(LOG, vector<int>(N + 1));
    for(int v = 1; v <= N; v++) up[0][v] = Q[v];
    for(int i = 1; i < LOG; i++){
        for(int v = 1; v <= N; v++){
            up[i][v] = up[i - 1][up[i - 1][v]];
        }
    }
    // For each label s (initially at position s), jump K times along Q
    vector<int> res(N + 1, 0);
    for(int s = 1; s <= N; s++){
        int cur = s;
        long long x = K;
        for(int i = 0; x; i++, x >>= 1){
            if(x & 1) cur = up[i][cur];
        }
        res[cur] = s; // label s ends at position cur
    }
    for(int i = 1; i <= N; i++) cout << res[i] << '\n';
    return 0;
}
