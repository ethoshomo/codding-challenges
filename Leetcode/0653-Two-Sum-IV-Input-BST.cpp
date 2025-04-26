/* 653. Two Sum IV - Input is a BST

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 
Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

////////////////// Solução 1: mais lenta
bool helper(TreeNode* r, unordered_map<int,int>& m, int& k){
    if(!r) return false;

    if(m.find(k-r->val) != m.end())
        return true;
    
    bool left = false, right = false;
    m[r->val] = 1;
    
    if(r->left) 
        left = helper(r->left, m, k);
    
    if(r->right) 
        right = helper(r->right, m, k);

    return max(left, right);
}

bool findTarget_slowly(TreeNode* root, int k) {
    unordered_map<int,int> map;
    return helper(root, map, k);
}

////////////////// Solução 2: Mais rápida
/* 
    A ideia implementa uma busca do complemento 
    da soma na árvore. Por exemplo: k = 9. 

    Se a raiz tem valor root->val = 2, busca-se
    o 7 na esturutra da própria árvore. A busca
    é mais rápida que as recursões de travessia e
    não usa memória extra.
*/
bool find(TreeNode* root, TreeNode* curr, int val) {
    if (!root) 
        return false;

    if (root->val == val && root != curr) 
        return true;
    else if (val < root->val) 
        return find(root->left, curr, val);

    return find(root->right, curr, val);
}

bool dfs(TreeNode* root, TreeNode* curr, int k) {
    if (!curr) 
        return false;

    if (find(root, curr, k - curr->val)) 
        return true;

    return dfs(root, curr->left, k) || dfs(root, curr->right, k);
}

bool findTarget(TreeNode* root, int k) {
    return dfs(root, root, k);
}

int main(){

    TreeNode* l21 = new TreeNode(2);
    TreeNode* l22 = new TreeNode(4);
    TreeNode* l23 = new TreeNode(7);
    
    TreeNode* l11 = new TreeNode(3, l21, l22);
    TreeNode* l12 = new TreeNode(6, nullptr, l23);

    TreeNode* root = new TreeNode(5, l11, l12);
    int k = 9;
    
    cout << (findTarget(root, k) ? "TRUE" : "FALSE");

    return 0;
}