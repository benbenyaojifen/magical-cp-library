#include<bits/stdc++.h>
using namespace std;
int A, B, n, m;
int ver[2010], hor[2010], v[2010], h[2010];
vector<tuple<int, int, int>> edges;
long long ans = 0;
struct DSU {
vector<int> e;
DSU(int N) {
   e = vector<int>(N, -1);
}


// get representive component (uses path compression)
int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }


bool same_set(int a, int b) { return get(a) == get(b); }


int size(int x) { return -e[get(x)]; }


bool unite(int x, int y) {  // union by size
 x = get(x), y = get(y);
 if (x == y) return false;
 if (e[x] > e[y]) swap(x, y);
 e[x] += e[y];
 e[y] = x;
 return true;
}
};
int main(void){


   ifstream cin("fencedin.in");
   ofstream cout("fencedin.out");


   cin >> A >> B >> n >> m;


   for(int i = 0; i < n; i++){
       cin >> v[i];
   }
   v[n] = 0;
   v[n+1] = A;


   for(int i = 0; i < m; i++){
       cin >> h[i];
   }
   h[m] = 0;
   h[m+1] = B;


   sort(v, v+n+2);
   sort(h, h+m+2);


   for(int i = 0; i <= m; i++){
       int deltay = h[i+1]-h[i];
       for(int j = 0; j < n; j++){
           int a = i*(n+1)+j;
           int b = i*(n+1)+j+1;
           edges.push_back(tie(deltay, a, b));
       }
   }


   for(int i = 0; i <= n; i++){
       int deltax = v[i+1]-v[i];
       for(int j = 0; j < m; j++){
           int a = j*(n+1)+i;
           int b = (j+1)*(n+1)+i;
           edges.push_back(tie(deltax, a, b));
       }
   }


   sort(edges.begin(), edges.end());


   DSU du((n+1)*(m+1));


   for(auto u: edges){
       if(du.unite(get<1>(u), get<2>(u))){
           ans += get<0>(u);
           
           // if(du.size(get<1>(u)) == (n+1)*(m+1)){
           //     cout << ans << endl;
           //     return 0;
           // }
       }
   }


   cout << ans << endl;


   return 0;
}

