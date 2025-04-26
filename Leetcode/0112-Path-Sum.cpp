/* 112. Path Sum

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Example 3:
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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

bool hasPathSum_recursive(TreeNode* root, int targetSum) {
    
    if(!root) return false;
    
    if(!root->right && !root->left){
        if(targetSum-root->val == 0) 
            return true;
        else 
            return false;
    }
    
    bool right = false;
    bool left = false;

    if(root->left) {
        left = hasPathSum_recursive(root->left, targetSum-root->val);
        if(left) return true;
    }
    if(root->right) {
        right = hasPathSum_recursive(root->right, targetSum-root->val);
        if(right) return true;
    }

    return max(right, left);
}

// Esse caminho gasta mais memória
bool hasPathSum(TreeNode* root, int targetSum) {

    if(!root) return false;
    if(!root->right && !root->left && root->val == targetSum) return true;

    pair<TreeNode*,int> aux;   

    deque<pair<TreeNode*, int>> stack;
    stack.push_front({root, root->val});

    while(!stack.empty()){
        aux = stack.front();
        stack.pop_front();

        if (!aux.first->left && !aux.first->right && aux.second == targetSum)
            return true;

        if (aux.first->left) 
            stack.push_front({
                aux.first->left, 
                aux.first->left->val+aux.second
            });
        if (aux.first->right) 
            stack.push_front({
                aux.first->right, 
                aux.first->right->val+aux.second
            });
        }

        return false;
}

int main(){
    
    TreeNode* l31 = new TreeNode(7);
    TreeNode* l32 = new TreeNode(2);
    TreeNode* l33 = new TreeNode(1);

    TreeNode* l21 = new TreeNode(11, l31, l32);
    TreeNode* l22 = new TreeNode(13);
    TreeNode* l23 = new TreeNode(4, nullptr, l33);

    TreeNode* l11 = new TreeNode(4, l21, nullptr);
    TreeNode* l12 = new TreeNode(8, l22, l23);

    TreeNode* root = new TreeNode(5, l11, l12);

    cout << (hasPathSum(root, 22)? "TRUE" : "FALSE");

    return 0;
}