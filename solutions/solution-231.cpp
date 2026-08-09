#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long hi = 2 * 1e9, low = 1;
    while(low <= hi){
        long long mid = low + (hi - low) / 2;
        cout << mid << endl;
        string inst;
        cin >> inst;
        if(inst == "FLOATS"){
            hi = mid - 1;
        }
        else if (inst == "SINKS"){
            low = mid + 1;
        } else {
            exit(0);
        }
    }
    return 0;
}