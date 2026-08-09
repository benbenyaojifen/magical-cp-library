#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t = 5;
    while (t--) {
        string s; getline(cin, s);
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            j = i;
            string cur = "";
            while (j < s.size() && isdigit(s[j])) {
                cur += s[j];
                j++;
                i = j - 1;
            }
            if (!cur.empty()) cnt += stoi(cur);
        }
        int open = 0, depth = 0, max_depth = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
                depth++;
                max_depth = max(max_depth, depth);
            } else if (c == ')') {
                depth--;
            }
        }
        int edges = 2 * open;
        int roads = 2 * edges - max_depth;
        cout << roads << " " << cnt << '\n';
    }
    return 0;
}