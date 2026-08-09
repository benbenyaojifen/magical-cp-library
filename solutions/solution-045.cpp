#include "stdc.h"

struct DSU {
    vector<int> parent;   
    vector<int> rank;      

    DSU(int n) : parent(n + 1), rank(n + 1, 0) {
        iota(parent.begin(), parent.end(), 0);  // parent[i] = i
    }

    int find(int x) {                      
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {              
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;      

        if (rank[rootX] > rank[rootY]) {    
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {                            
            parent[rootY] = rootX;
            rank[rootX]++;                 
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = people, m = classes
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int k; cin >> k;                  
        int first;
        cin >> first;  // representative student
        for (int i = 1; i < k; i++) {       // union with the rest
            int x; 
            cin >> x;
            dsu.unite(first, x);
        }
    }
    //person one is by default infected 
    vector<int> infected;
    int person = dsu.find(1);
    for (int i = 1; i <= n; ++i){
        if (dsu.find(i) == person){
        infected.push_back(i);
    }
  }
    cout << infected.size() << '\n';
    for (int i = 0; i < infected.size(); i++)
        cout << infected[i] << (i + 1 == infected.size() ? '\n' : ' ');
    return 0;
}
