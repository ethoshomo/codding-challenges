/* 236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1
 
Constraints:
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* A ideia aqui é que, como é garantido ter uma solução, podemos
    verificar os dois lados retornando o primeiro que encontrar.
    Se os dois lados possuirem retorno, o ancestral é o root;
    caso contrário, se os dois nós estão no mesmo lado, o
    primeiro a ser encontrado é ancestral comum. */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
     
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left == nullptr) 
        return right;
    else if(right == nullptr)
        return left;
    return root;
}

int main(){
    
    TreeNode* l31 = new TreeNode(7);
    TreeNode* l32 = new TreeNode(4);

    TreeNode* l21 = new TreeNode(6);
    TreeNode* l22 = new TreeNode(2, l31, l32);
    TreeNode* l23 = new TreeNode(0);
    TreeNode* l24 = new TreeNode(8);
    
    TreeNode* l11 = new TreeNode(5, l21, l22);
    TreeNode* l12 = new TreeNode(1, l23, l24);

    TreeNode* root = new TreeNode(3, l11, l12);

    TreeNode* p = l32;
    TreeNode* q = l22;

    auto r = lowestCommonAncestor(root, p, q);
    cout << r->val;

    return 0;
}