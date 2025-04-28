/* 230. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 
Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
*/
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* root, int k, int& counter){
    if(!root) return -1;

    int aux = -1;
    if(root->left){
        aux = helper(root->left, k, counter);
        if(aux >=0) return aux;
    }
    counter++;
    if(counter == k) return root->val;
    if(root->right) {
        aux = helper(root->right, k, counter);
        if(aux >=0) return aux;
    }
    return -1;
}

int kthSmallest(TreeNode* root, int k) {
    int counter = 0;
    return helper(root, k, counter);
}

int main(){

    TreeNode *l31 = new TreeNode(1);
    TreeNode *l21 = new TreeNode(2,l31, nullptr);
    TreeNode *l22 = new TreeNode(4);
    TreeNode *l11 = new TreeNode(3, l21, l22);
    TreeNode *l12 = new TreeNode(6);
    TreeNode *root = new TreeNode(5, l11, l12);

    cout << kthSmallest(root, 3);

    return 0;
}