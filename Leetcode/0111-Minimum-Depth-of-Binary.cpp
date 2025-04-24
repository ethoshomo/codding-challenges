/* 111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 
Constraints:
The number of nodes in the tree is in the range [0, 105].
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

//////////////////////////////////// DFS
// Apesar de ter batido 100% em run time, vou treinar
// a BFS, pois ela me parece mais promissora, afinal,
// quando atingir o menor nível de profundidade, irá
// encerrar o algoritmo.
int helper(TreeNode* n, int l){
    if(!n->left && !n->right) return l;

    int ln = 1000000, rn = 1000000;
    if(n->left) ln = helper(n->left, l+1);
    if(n->right) rn = helper(n->right, l+1);
    return min(ln, rn);
}

int minDepth_dfs(TreeNode* root) {
    return helper(root, 1);
}


/////////////////////////////////////// BFS
// O busca em profundidade foi mais rápido para
// os casos de testes.
int minDepth(TreeNode* root) {
    if(!root) return 0;

    TreeNode* aux;
    deque<TreeNode*> d;
    d.push_back(root);

    int level = 0;
    while(!d.empty()){
        
        level += 1;
        int n = d.size();

        for(int i = 0; i < n; i++){
            aux = d.front();
            d.pop_front();
            if(!aux->left && !aux->right) 
                return level;
            
            if(aux->left) d.push_back(aux->left);
            if(aux->right) d.push_back(aux->right);
        }
    }

    return 0;
}

int main(){

    TreeNode* l21 = new TreeNode(15);
    TreeNode* l22 = new TreeNode(7);
    TreeNode* l11 = new TreeNode(9);
    TreeNode* l12 = new TreeNode(20,l21, l22);
    TreeNode* root = new TreeNode(3, l11, l12);

    cout <<  minDepth(root);

    return 0;
}