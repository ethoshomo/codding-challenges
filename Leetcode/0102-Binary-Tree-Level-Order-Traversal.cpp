/* 102. Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

*/
#include <iostream>
#include <vector>
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

vector<vector<int>> levelOrder(TreeNode* root) {
    
    vector<vector<int>> r;
    if(!root) return r;

    TreeNode* aux = nullptr;
    deque<TreeNode*> d;
    d.push_back(root);

    while(!d.empty()){

        int level = d.size();
        vector<int> values;
        for(int i = 0; i < level; i++){
            aux = d.front();
            d.pop_front();
            values.push_back(aux->val);
            if(aux->left)d.push_back(aux->left);
            if(aux->right)d.push_back(aux->right);
        }
        r.push_back(values);
    }

    return r;
}

int main(){

    TreeNode* l21 = new TreeNode(15);
    TreeNode* l22 = new TreeNode(7);
    TreeNode* l11 = new TreeNode(9);
    TreeNode* l12 = new TreeNode(20,l21, l22);
    TreeNode* root = new TreeNode(3, l11, l12);

    auto r = levelOrder(root);

    for(auto c: r){
        for(auto d: c){
            cout << d << ' ';
        }
        cout << '\n';
    }

    return 0;
}