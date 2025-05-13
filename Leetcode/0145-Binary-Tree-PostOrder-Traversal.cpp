/* 145. Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]
Explanation:

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]
Explanation:

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]


Constraints:
The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
Follow up: Recursive solution is trivial, could you do it iteratively?
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

void helper(TreeNode* r, vector<int>& s){
    if(!r) return;
    if(r->left) helper(r->left, s);
    if(r->right) helper(r->right, s);
    s.push_back(r->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> r;
    if(!root) return r;
    helper(root, r);
    return r;
}

int main(){

    TreeNode* n31 = new TreeNode(6);
    TreeNode* n32 = new TreeNode(7);
    TreeNode* n33 = new TreeNode(9);
    TreeNode* n21 = new TreeNode(4);
    TreeNode* n22 = new TreeNode(5, n31,n32);
    TreeNode* n23 = new TreeNode(8, n33, nullptr);
    TreeNode* n11 = new TreeNode(2,n21, n22);
    TreeNode* n12 = new TreeNode(3, nullptr, n23);
    TreeNode* n00 = new TreeNode(1, n11, n12);

    auto it = postorderTraversal(n00);

    for(auto &i : it) cout << i << ' ';

    return 0;
}