#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int begin, end;
        cin >> begin >> end;
        v.emplace_back(begin, end);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto[s, f] : v){
        if(!pq.empty() && pq.top() <= s){
            pq.pop();
        }
        pq.push(f);
    }
    cout << pq.size() << '\n';
    return 0;
}