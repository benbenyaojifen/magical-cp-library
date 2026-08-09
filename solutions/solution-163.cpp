#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, k, q; cin >> n >> k >> q;
    ///we maintain previous window and updated window. suprisingly easier than p1
    //throwing 2d seg tree at this problem is too hard so we just brute force!!!!
    //since k is so tiny we brute force. We do not need to loop all k * k squares only the ones influenced
    //the cur[i][j] will be the sum of beauty values inside the k × k square and top left corner is row i col j
    vector<vector<int>> pre(n, vector<int>(n)), cur(n, vector<int>(n));
    int ans = 0;
    while (q--) {
        int r, c, v; cin >> r >> c >> v;
        r--; c--;
        int change = v - pre[r][c];
        pre[r][c] = v;
        // boundaries of winodws
        int topr = max(0, r - k + 1), bottomr = min(r, n - k), leftcol = max(0, c - k + 1), rightcol = min(c, n - k);
        //all windows affected by this update 
        for (int i = topr; i <= bottomr; i++) {
            for (int j = leftcol; j <= rightcol; j++) {
                cur[i][j] += change;
                ans = max(ans, cur[i][j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}