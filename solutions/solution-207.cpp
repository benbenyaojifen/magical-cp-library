#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int r, c; cin >> r >> c;
    while (true) {
        if (r == 0 && c == 0) break;
        vector<vector<char>> g(r, vector<char>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> g[i][j];
            }
        }
        auto calc = [&] (int i, int j) {
            if (g[i][j] == '.' || g[i][j] == '*') return 0;
            return g[i][j] - '0';
        };
        vector<int> dp(r, -inf), odp(r, -inf);
        odp[r - 1] = calc(r - 1, 0);
        for (int i = r - 2; i >= 0; i--) {
            if (g[i][0] == '*') break;
            odp[i] = odp[i + 1] + calc(i, 0);
        }
        for (int i = 1; i < c; i++) {
            vector<int> cur(r, -inf), down(r, -inf), up(r, -inf); // cur[j] = max coin you get by moving right into column i at row j
            for (int j = 0; j < r; j++) {
                if (g[j][i] == '*' || odp[j] == -inf) continue;
                cur[j] = odp[j] + calc(j, i);
            }
            for (int j = 0; j < r; j++) {
                if (g[j][i] == '*') {
                    down[j] = -inf;
                    continue;
                }
                int best = cur[j];
                if (j > 0 && down[j - 1] != -inf) {
                    best = max(best, down[j - 1] + calc(j, i));
                }
                down[j] = best;
            }
            for (int j = r - 1; j >= 0; j--) {
                if (g[j][i] == '*') {
                    up[j] = -inf;
                    continue;
                }
                int best = cur[j];
                if (j < r - 1 && up[j + 1] != -inf) {
                    best = max(best, up[j + 1] + calc(j, i));
                }
                up[j] = best;
            }
            for (int j = 0; j < r; j++) {
                dp[j] = max(down[j], up[j]);
            }
            swap(odp, dp);
        }
        cout << odp[r - 1] << '\n';
        cin >> r >> c;
    }
    return 0;
}