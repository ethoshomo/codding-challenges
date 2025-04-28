/* 1382. Balance a Binary Search Tree

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:
Input: root = [2,1,3]
Output: [2,1,3]

Constraints:
The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// VERSÃO FUNCIONAR LENTA
TreeNode* createBST_(vector<int> v, int l, int r){
    if(l > r) return nullptr;
    int i = (l+r)/2;
    int val = v[i];
    return new TreeNode(
        val, 
        createBST_(v, l, i-1), 
        createBST_(v, i+1, r)
    );
}

void read_tree(TreeNode* r, vector<int> &q){
    if(!r) return;
    if(r->left) read_tree(r->left, q);
    q.push_back(r->val);
    if(r->right) read_tree(r->right, q);
}

TreeNode* balanceBST_(TreeNode* root) {
    vector<int> q;
    read_tree(root, q);
    sort(q.begin(), q.end());
    return createBST_(q, 0, static_cast<int>(q.size()-1));
}


// VERSÃO RÁPIDA
/*
    A diferença entre as duas está no fato que a versão lenta
    cria toda a árvore, enquanto a versão abaixo apenas faz 
    a reoorganização dos nós existentens. É interessante notar
    também que os nós são coletados de forma ordenada (in order)
    para deixar a árvore final nas exigências de uma BST.

*/
TreeNode* makeBalancedBst(vector<TreeNode*>& store , int start , int end) {
    int mid = (end + start) / 2;
    TreeNode* root = store[mid];
    if (start > end) return nullptr;

    root->left = makeBalancedBst(store, start, mid - 1);
    root->right = makeBalancedBst(store, mid + 1, end);

    return root;
}

void storeInVector(TreeNode* root, vector<TreeNode*>& store) {
    if (root == NULL) return;
    if (root->left) storeInVector(root->left, store);
    store.push_back(root);
    if (root->right) storeInVector(root->right, store);
}

TreeNode* balanceBST(TreeNode* root) {
    if (root == NULL) return 0;
    vector<TreeNode*> store;
    storeInVector(root , store);
    return makeBalancedBst(store , 0 , store.size()-1);
}
int main(){

    TreeNode *l31 = new TreeNode(5);
    TreeNode *l21 = new TreeNode(0);
    TreeNode *l22 = new TreeNode(1);
    TreeNode *l11 = new TreeNode(2, l31, nullptr);
    TreeNode *l12 = new TreeNode(3, l21, l22);
    TreeNode *root = new TreeNode(4, l11, l12);

    auto it = balanceBST(root);
    cout << it->val;

    return 0;
}