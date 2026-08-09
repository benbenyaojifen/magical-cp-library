#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    if(n == 3){
        int a, b, c; cin >> a >> b >> c;
         if(c ==3) cout << "3 3" << '\n';
         else cout << (a == 3 ? "1 1" : "2 2") << '\n';
    } else if(n < 3){
        if(n == 1) cout << "1 1" << endl;
        else {
            int a, b; cin >> a >> b;
            cout << (b == 2 ? "2 2" : "1 1");
        }
    } else {
            int a = 0, z = 0, k = 0;
            for(int i = 0; i < n; i++){
                if(i == 0) cin >> a;
                else if(i == n - 1) cin >> z;
                else cin >> k;
            }
            if(a == 1){
                cout << "2 " << n << '\n';
            } else if(z == 1){
                cout << "1 " << n - 1 << '\n';
            } else{
                cout << "1 " << n << '\n';
        }
    }
}