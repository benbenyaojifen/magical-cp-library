#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
void dfs(int row, vector<bool>& col, vector<bool>& dp, vector<bool>& dm){
    if(row == n) { // placed all the queens(one valid solution)
        ans++;
        return;
    }
    //try to place a queen in each column of the current row
    for(int i = 0; i < n; i++){
        int right_up = row + i;
        int left_down = row - i + n - 1; // + n - 1 to adjust for negative index
        //check if it is a valid placement
        if(!col[i] && !dp[right_up] && !dm[left_down]){
            //place a queen and mark placed
            col[i] = true; dp[right_up] = true; dm[left_down] = true;
            dfs(row + 1, col, dp, dm); // move on to the next queen
            //recite 
            col[i] = false; dp[right_up] = false; dm[left_down] = false;
        }

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<bool> col(n, false), dp(2 * n - 1, false), dm(2 * n - 1, false);
    dfs(0, col, dp, dm);
    cout << ans << '\n';
    return 0;
}