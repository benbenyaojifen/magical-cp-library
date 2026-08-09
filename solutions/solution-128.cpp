#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int s, l; cin >> s >> l;
    queue<pair<int, int>> q;
    stack<pair<int, int>> st;
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
        int p, m, g; cin >> p >> m >> g;
        v.emplace_back(p, m, g);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        auto[x, y, z] = v[i];
        if(x > s) q.push({y, z});
        else st.push({y, z});
    }
    while((!st.empty() && st.top().first <= l) || (!q.empty() && q.front().first <= l)){
        if(!q.empty() && q.front().first <= l){
            l += q.front().second;
            q.pop();
        } 
        if(!st.empty() && st.top().first <= l){
            l += st.top().second;
            st.pop();
        }
    }
    cout << l << '\n';
    return 0;
}