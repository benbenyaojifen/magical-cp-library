
#include <bits/stdc++.h>

using namespace std;

struct triplet{
    int x, y, z;
    triplet(int a, int b, int c) : x(a), y(b), z(c){}
    bool operator<(const triplet &o) const{
        if(x != o.x) return x < o.x;
        if(y != o.y) return y < o.y;
        return z < o.z;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    set<triplet> s;
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            int sum = v[i] + v[j];
            auto pos = lower_bound(v.begin(), v.end(), sum);
            if(pos == v.end() || v[pos - v.begin()] != sum) continue;
            if(pos != v.end() && !s.count({v[i], v[j], sum})){
                cnt++;
                s.insert({v[i], v[j], sum});
            }
        }
    }
    cout << (cnt == 0 ? -1 : cnt) << '\n';
    return 0;
}