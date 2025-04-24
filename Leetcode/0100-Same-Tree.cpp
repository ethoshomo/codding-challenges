/* 100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false

Constraints:
The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
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

bool isSameTree_clean_version(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;
    
    if (p->val == q->val)
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    
    return false;
}


bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if((p && !q) || (!p && q)) return false;
    
    TreeNode* auxp = nullptr;
    TreeNode* auxq = nullptr;

    deque<TreeNode*> dp;
    dp.push_back(p);

    deque<TreeNode*> dq;
    dq.push_back(q);

    while(!dp.empty() && !dq.empty()){
        
        int size = dp.size();
        for(int i = 0; i < size; i++){
            
            auxp = dp.front();
            auxq = dq.front();
            
            dp.pop_front();
            dq.pop_front();

            if((auxp->val != auxq->val) || 
                (!auxp->right && auxq->right) ||
                (auxp->right && !auxq->right) ||
                (!auxp->left && auxq->left) ||
                (auxp->left && !auxq->left)
            ) return false;
            
            if(auxp->left && auxq->left){
                dp.push_back(auxp->left);
                dq.push_back(auxq->left);
            }

            if(auxp->right && auxq->right){
                dp.push_back(auxp->right);
                dq.push_back(auxq->right);
            }
        }
    }
    
    return dp.empty() == dq.empty();
}

int main(){

    TreeNode* l21 = new TreeNode(4);
    TreeNode* l22 = new TreeNode(5);
    TreeNode* l11 = new TreeNode(2);
    TreeNode* l12 = new TreeNode(3,l21, l22);
    TreeNode* root = new TreeNode(1, l11, l12);
    
    TreeNode* root211 = new TreeNode(2);
    TreeNode* root2l12 = new TreeNode(3);
    TreeNode* root2 = new TreeNode(1, root211, root2l12);

    cout << isSameTree(root, root2);

    return 0;
}