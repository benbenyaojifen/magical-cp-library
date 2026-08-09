#include "stdc.h"

int main() {
    int n;
    cin >> n;
    vector<int> w (n + 1);
    for(int i = 0; i < w.size(); i++){
        cin >> w[i];
    }
    vector<int> h(n);
    for(int i = 0; i < h.size(); i++){
        cin >> h[i];
    }
    int index = 0;
    double ans = 0;
    for(int i = 0; i < w.size() - 1; i++){
        ans += h[index] * (w[i] + w[i + 1]) / 2.0;
        index++;
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}