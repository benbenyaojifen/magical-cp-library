#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long ll;
const int INF = 0x3f3f3f3f;
//#define int long long 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    unordered_set<int>s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';
    return 0;
}
