#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v),left(nullptr), right(nullptr){}

};
int height, indx;
vector<int> seq;
Node* build(int depth){
    if(depth > height) return nullptr;
    Node* root = new Node(0);
    root->left = build(depth + 1);
    root->val = seq[indx++];
    root->right = build(depth + 1);
    return root; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> height;
    int total = (1 << height) - 1;
    seq.resize(total);
    for(int i = 0; i < total; i++){
        cin >> seq[i];
    }
    indx = 0;
    Node* root = build(1);
    queue<Node*> q;
    q.push(root);
    priority_queue<int> pq;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* cur = q.front(); q.pop();
            cout << cur->val << (i == size - 1 ? "\n" : " ");
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return 0;
}