/* 543. Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1
 
Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/
#include <iostream>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* root, int& diameter){
    if(!root) return 0;
    int left = root->left ? helper(root->left, diameter) : 0;
    int right = root->right ? helper(root->right, diameter) : 0;
    diameter = max(diameter, left+right);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    helper(root, diameter);
    return diameter;
}

int main(){
    
    TreeNode* l21 = new TreeNode(4);
    TreeNode* l22 = new TreeNode(5);
    
    TreeNode* l11 = new TreeNode(2, l21, l22);
    TreeNode* l12 = new TreeNode(3);

    TreeNode* root = new TreeNode(1, l11, l12);

    cout << diameterOfBinaryTree(root);

    return 0;
}