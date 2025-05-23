/* 98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 
Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* node, long minVal, long maxVal) {
    if (!node) return true;

    if (node->val <= minVal || node->val >= maxVal)
        return false;

    return helper(node->left, minVal, node->val) &&
           helper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return helper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
}


int main(){
    // FALSE
    //TreeNode* n21 = new TreeNode(3);
    //TreeNode* n22 = new TreeNode(6);
    //TreeNode* n11 = new TreeNode(1);
    //TreeNode* n12 = new TreeNode(4, n21, n22);
    //TreeNode* n00 = new TreeNode(5, n11, n12);

    // TRUE
    TreeNode* n11 = new TreeNode(1);
    TreeNode* n12 = new TreeNode(3);
    TreeNode* n00 = new TreeNode(5, n11, n12);

    // FALSE
    //TreeNode* n21 = new TreeNode(3);
    //TreeNode* n22 = new TreeNode(7);
    //TreeNode* n11 = new TreeNode(4);
    //TreeNode* n12 = new TreeNode(6, n21, n22);
    //TreeNode* n00 = new TreeNode(5, n11, n12);

    cout << (isValidBST(n00) ? "TRUE" : "FALSE");
    

    return 0;
}