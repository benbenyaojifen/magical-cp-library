#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int idx;
};

Node better(Node a, Node b) {
    if (a.val != b.val) return (a.val > b.val ? a : b);
    return (a.idx < b.idx ? a : b); // leftmost on tie
}

struct SegTree {
    int n;
    vector<Node> t;

    SegTree(const string &s) {
        n = s.size();
        t.resize(4*n);
        build(s, 1, 0, n-1);
    }

    void build(const string &s, int v, int l, int r) {
        if (l == r) {
            t[v] = {s[l] - '0', l};
            return;
        }
        int m = (l+r)/2;
        build(s, v*2, l, m);
        build(s, v*2+1, m+1, r);
        t[v] = better(t[v*2], t[v*2+1]);
    }

    Node query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {-1, INT_MAX};
        if (ql <= l && r <= qr) return t[v];
        int m = (l+r)/2;
        return better(
            query(v*2, l, m, ql, qr),
            query(v*2+1, m+1, r, ql, qr)
        );
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    string s;
    cin >> k >> s;

    int m = s.size();
    SegTree st(s);

    int need = k;
    int pos = 0;

    vector<char> ans;

    while (need > 0) {

        int max_pick = m - need;   // right boundary of valid window

        Node best = st.query(pos, max_pick);

        ans.push_back(char('0' + best.val));

        pos = best.idx + 1;        // continue after chosen digit
        need--;
    }

    for (char c : ans) cout << c;
    cout << '\n';
}
