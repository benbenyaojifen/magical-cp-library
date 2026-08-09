#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    cin.ignore();
    for (int t = 0; t < n; t++) {
        string s; getline(cin, s);
        vector<string> v;
        string a = "";
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            if (c == ' ') {
                v.push_back(a);
                a = "";
            } else {
                a += c;
            }
        }
        v.push_back(a);
        for (int i = 0; i < v.size(); i++) {
            string ss = v[i];
            if (ss.size() == 4) {
                for(int j = 0; j < 4; j++) {
                    cout << "*";
                }
            } else {
                for (char c : ss) cout << c;
            }
            cout << (i == v.size() - 1 ? "\n" : " ");
        }
    }
    return 0;
}