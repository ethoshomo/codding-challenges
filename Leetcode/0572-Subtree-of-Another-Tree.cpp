/*  572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

Constraints:
The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
*/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSame(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->val != b->val) return false;

    return isSame(a->left, b->left) && isSame(a->right, b->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;

    if (isSame(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main(){
    TreeNode* n31 = new TreeNode(0);
    TreeNode* n21 = new TreeNode(1);
    TreeNode* n22 = new TreeNode(2, n31, nullptr);
    TreeNode* n11 = new TreeNode(4, n21, n22);
    TreeNode* n12 = new TreeNode(5);
    TreeNode* n00 = new TreeNode(3, n11, n12);

    TreeNode* m21 = new TreeNode(1);
    TreeNode* m22 = new TreeNode(2);
    TreeNode* m11 = new TreeNode(4, m21,m22);

    cout << (isSubtree(n00, m11) ? "TRUE" : "FALSE");

    return 0;
}