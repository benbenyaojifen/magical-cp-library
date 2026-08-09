#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    if (s.size() == 1 || s.find_first_not_of('0', 1) == -1) {
        cout << 0 << '\n';
        return 0;
    }
    int first = s[0] - '0' + 1;
    string want = to_string(first);
    for(int i = 0; i < s.length() - 1; i++){
        want.append("0");
    }
    int x = want.length(), y = s.length();
    vector<int> a(x), b(x, 0);
    for(int i = 0; i < x; i++){
        a[i] = want[x - 1 - i] - '0';
    }
    for(int i = 0; i < y; i++){
        b[i] = s[y - 1 - i] - '0';
    }
    for(int i = 0; i < x; i++){
        a[i] -= b[i];
        if (a[i] < 0) {
            a[i] += 10;
            a[i + 1]--;
        }
    }
    int pos = x - 1;
    //remove leading 0
    while(pos > 0 && a[pos] == 0){
        pos--;
    }
    string ans;
    while(pos >= 0){
        char temp = (char) (a[pos] + '0');
        ans.push_back(temp);
        pos--;
    }
    cout << ans << '\n';
}   