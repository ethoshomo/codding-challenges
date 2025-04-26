/* 226. Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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

TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    if(!root->right && !root->left) return root;
    if(root->left) invertTree(root->left);
    if(root->right) invertTree(root->right);
    swap(root->left,root->right);
    return root;
}

int main(){
    
    TreeNode* l21 = new TreeNode(1);
    TreeNode* l22 = new TreeNode(3);
    TreeNode* l23 = new TreeNode(4);
    TreeNode* l24 = new TreeNode(9);
    
    TreeNode* l11 = new TreeNode(2, l21, l22);
    TreeNode* l12 = new TreeNode(7, l23, l24);

    TreeNode* root = new TreeNode(4, l11, l12);

    auto r = invertTree(root);

    return 0;
}