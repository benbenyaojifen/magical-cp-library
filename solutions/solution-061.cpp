#include <bits/stdc++.h>

using namespace std;
// Oh I just realized it is not a greedy problem
// should have looked at the constraint
//it is a backtracking/dp question
//大意了没有闪
struct course {
    int s, f, b, e, m, v, total;
};
int n, m;
vector<course> a;
bool bad[21][21];
bool chose[21];
long long best = -1;
// index is next course to consider
// count is how many chosen so far
// sum is total value so far
void dfs(int indx, int cnt, long long sum){
    if (cnt + (n - indx) < m) return; // stop if we cannot reach m even if we pick all courses
    if(indx == n){
        if(cnt >= m){
            best = max(best, sum);
            return;
        }
    }
    //if mandatory, we must include it 
    if(a[indx].m){
        bool good = true;
        //check if conflict with previously chosen courses
        for(int i = 0; i < indx; i++){
            if(chose[i] && bad[indx][i]){
                good = false;
                break;
            }
        }
        if(good){
            chose[indx] = true;
            dfs(indx + 1, cnt + 1, sum + a[indx].total);
            chose[indx] = false;
        } // if we cannot chose mandatory, we cannot proceed with the current arrangement since mandatory cannot be satisfied 
    } else {
        //skip optional course
        dfs(indx + 1, cnt, sum);
        // if no conflict, try including it
        bool good = true;
         //check if conflict with previously chosen courses
        for(int i = 0; i < indx; i++){
            if(chose[i] && bad[indx][i]){
                good = false;
                break;
            }
        }
        if(good){
            chose[indx] = true;
            dfs(indx + 1, cnt + 1, sum + a[indx].total);
            chose[indx] = false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].s >> a[i].f >> a[i].b >> a[i].e >> a[i].m >> a[i].v;
        a[i].total = (a[i].f - a[i].s + 1) * (a[i].e - a[i].b + 1) * a[i].v;
    }
    //preprocess conflicting 
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            bool bad_day = !(a[i].f < a[j].s || a[j].f < a[i].s); // i finishes before j starts or j finishes before i starts
            bool bad_time = !(a[i].e < a[j].b || a[j].e < a[i].b); // the same for time
            if(bad_day && bad_time) bad[i][j] = bad[j][i] = true; // conflict if on same day and at same time
        }
    }
    //check if mandatory days conlfict each other or not , if yes then it is impossible 
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i].m){ // mandatory 
            count++;
            for(int j = i + 1; j < n; j++){
                if(a[j].m && (bad[i][j] || bad[j][i])){
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    dfs(0, 0, 0LL);
    cout << best << '\n';
    return 0;
}