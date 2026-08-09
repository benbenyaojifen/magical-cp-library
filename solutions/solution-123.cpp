#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n);
    stack<int> l, r;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = v.size() -1; i >= 0; i--) {
        l.push(v[i]);
    }
    sort(v.begin(), v.end());
    int pos = 1;
    vector<string> ans;
    while (pos <= n) {
        int x = v[n - pos];
        int sorted = pos - 1;
        while (l.top() != x) {
            int cur = l.top();
            l.pop();
            ans.push_back("UZMI L L");
            r.push(cur);
            ans.push_back("STAVI L D");
        }
        int hand = l.top();
        l.pop();
        ans.push_back("UZMI L L");
        while (l.size() > sorted) {
            int cur = l.top();
            l.pop();
            ans.push_back("UZMI D L");
            r.push(cur);
            ans.push_back("STAVI D D");
        }
        l.push(hand);
        ans.push_back("STAVI L L");
        while (!r.empty()) {
            int cur = r.top();
            r.pop();
            ans.push_back("UZMI L D");
            l.push(cur);
            ans.push_back("STAVI L L");
        }
        pos++;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
    return 0;
}
