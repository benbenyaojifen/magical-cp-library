#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> positive, negative;
    for(int i = 0; i < n; i++){
        int val; 
        cin >> val;
        if(val < 0) negative.push_back(-val);
        else positive.push_back(val);
    }
    vector<ll> psa(positive.size() + 1);
    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end(), greater<int>());
    int size = positive.size();
    for(int i = 1; i <= size; i++){
        psa[i] = psa[i - 1] + positive[i - 1];
    }
    ll ans = psa[min(k, size)];
    ll negative_sum = 0;
    for(int i = 0; i < negative.size() && k >= 2; i++){
        negative_sum += negative[i];
        k -= 2;
        ans = max(ans, negative_sum + psa[min(k, size)]);
    }  
    cout << ans <<'\n';
    return 0;
}