#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1LL << 60; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    string a, b; 
    getline(cin, a);
    getline(cin, b);
    int i = 0, j = 0, n = 0, m = 0;
    while (1) {
        if (i == a.size()) {
            m += b.size() - j;
            break;
        }
        if (j == b.size()) {
            n += a.size() - i;
            break;
        }
        if (a[i] == b[j]) {
            n++; m++;
            i++; j++;
        } else if (a[i] == 'R' && b[j] == 'G') {
            n++;
            j++;
        } else if (a[i] == 'G' && b[j] == 'R') {
            m++;
            i++;
        } else if (a[i] == 'R' && b[j] == 'B') {
            m++;
            i++;
        } else if (a[i] == 'B' && b[j] == 'R') {
            n++;
            j++;
        } else if (a[i] == 'B' && b[j] == 'G') {
            m++;
            i++;
        } else if (a[i] == 'G' && b[j] == 'B') {
            n++;
            j++;
        }
    }
    cout << n << '\n';
    cout << m << '\n';
    return 0;
}