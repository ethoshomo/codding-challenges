/* 700. Search in a Binary Search Tree

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
Input: root = [4,2,7,1,3], val = 5
Output: []

Constraints:
The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
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

TreeNode* searchBST(TreeNode* root, int val) {
    if(!root || root->val == val)
        return root;

    if(root->right && val > root->val)
        return searchBST(root->right, val);
    
    if(root->left && val < root->val)
        return searchBST(root->left, val);
    
    return nullptr;       
}

int main(){
    TreeNode* l21 = new TreeNode(1);
    TreeNode* l22 = new TreeNode(3);
    
    TreeNode* l11 = new TreeNode(2, l21, l22);
    TreeNode* l12 = new TreeNode(7);

    TreeNode* root = new TreeNode(4, l11, l12);
    int val = 2;

    auto it = searchBST(root, val);

    cout << it->val;

    return 0;
}