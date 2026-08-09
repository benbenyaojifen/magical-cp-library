#include <bits/stdc++.h>

using namespace std;
string convert_base(long long num, long long base){
    vector<int> remainder;
    if(num == 0){
        return "0";
    }
    while(num != 0){
        remainder.push_back(num % base);
        num /= base;
    }
    string temp;
    for(int i = remainder.size() -1; i >= 0; i--){
        temp += (char) ('0' + remainder[i]);
    }
    return temp;
}
long long p(long long base, long long exp){
    if(exp == 0) return 1;
    long long temp = p(base, exp / 2);
    if(exp & 1){
        return temp * temp * base;
    } else {
        return temp * temp;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 5;
    while(tt--){
        long long n1, b1, n2, b2, tar;
        cin >> n1 >> b1 >> n2 >> b2 >> tar;
        string s1 = to_string(n1), s2 = to_string(n2);
        long long a1 = 0, a2 = 0;
        int digit = 0;
        for(int i = s1.size() - 1; i >= 0; i--){
            long long pow = p(b1, digit);
            a1 += (s1[i] - '0') * pow;
            digit++;
        }
        digit = 0;
        for(int i = s2.size() - 1; i >= 0; i--){
            long long pow = p(b2, digit);
            a2 += (s2[i] - '0') * pow;
            digit++;
        }
        long long ans = a1 * a2;
        string out = convert_base(ans, tar);
        cout << out << '\n';
    }
    return 0;
}