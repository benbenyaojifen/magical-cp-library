#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

// put the right numbers after 1
vector<int> solve1(vector<int> a) {
    a.insert(a.end(), a.begin(), a.end());
    int idx1 = find(a.begin(), a.end(), 1) - a.begin();
    vector<int> b(a.begin() + idx1, a.end());
    for (int i = 0; i < n; i++) {
        if (b[i] != i + 1) {
            int miss = find(b.begin(), b.end(), i + 1) - b.begin();
            swap(b[i], b[miss]);
            break;
        }
    }
    b.resize(n);
    return b;
}

// move the 1 in front of the 2
vector<int> solve2(vector<int> a) {
    int pos2 = find(a.begin(), a.end(), 2) - a.begin();
    int pos1 = find(a.begin(), a.end(), 1) - a.begin();
    // swap 1 into the slot just before 2
    swap(a[(pos2 - 1 + n) % n], a[pos1]);
    // rotate so that 1 is at front
    int start = find(a.begin(), a.end(), 1) - a.begin();
    vector<int> b;
    b.reserve(n);
    for (int i = 0; i < n; i++)
        b.push_back(a[(start + i) % n]);
    return b;
}
// if 1 is already right after 2, just swap them
vector<int> solve3(vector<int> a) {
    int pos2 = find(a.begin(), a.end(), 2) - a.begin();
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[(pos2 + i) % n];
    if (b[1] == 1)
        swap(b[0], b[1]);
    return b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1) {
        cout << "1" << "\n";
        return 0;
    }
    auto a1 = solve1(arr);
    auto a2 = solve2(arr);
    auto a3 = solve3(arr);
    // pick lexicographically smallest
    vector<int> ans = min(min(a1, a2), a3);
    for (int i = 0; i < n; i++)
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    return 0;
}
