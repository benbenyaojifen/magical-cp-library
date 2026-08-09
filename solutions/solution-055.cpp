#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l, s;
    cin >> n >> l >> s;
    vector<pair<long long, long long>> v;
    for (int i = 0, a, b, c; i < n; i++)
    {
        cin >> a >> b >> c;
        v.emplace_back(a, c);
        v.emplace_back(b + 1, -c);
    }
    v.emplace_back(1, 0);
    v.emplace_back(l + 1, 0);
    sort(v.begin(), v.end());
    int cur = 0, prev = 1, ans = 0;
    for (auto &e : v)
    {
        long long pos = e.first;
        if (cur < s && pos > prev)
            ans += pos - prev;
        cur += e.second;
        prev = pos;
    }
    cout << ans << "\n";
}