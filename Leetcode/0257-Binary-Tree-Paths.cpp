/* 
257. Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]
 
Constraints:
The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Algoritmo Recursivo
void helper(TreeNode* n, vector<string>& r, string path){
    if(!n->left && !n->right){
        path += to_string(n->val);
        r.push_back(path);
        return;
    }
    path = path+ to_string(n->val)+"->";
    if(n->left) helper(n->left, r, path);
    if(n->right) helper(n->right, r, path);
}
vector<string> binaryTreePaths_recursivo(TreeNode* root) {
    vector<string> r;
    helper(root, r, "");
    return r;
}

/* 
    Versão otimizada: usa uma stack e um vetor de armazenamento 
    A ideia do algoritmo é empilhar todos os nós a partir de uma
    raiz e resolver cada ramificação uma por vez. Por exemplo:

        1
      /   \
     2     3
      \
       5

    Estado inicial: 
    stack: $ {root, 1}
    vector: 

    Iteração i = 0.
    stack: $ {2, 1->2}, {3, 1->3}
    vector:

    Iteração i = 1.
    stack: $ {2, 1->2}, 
    vector: "1->3"

    Iteração i = 2.
    stack: $ {5, 1->2->5}, 
    vector: "1->3"

    Iteração i = 3.
    stack: $ 
    vector: "1->3", "1->2->5"

    Stack vazia.
    Output = ["1->3", "1->2->5"]

*/
vector<string> binaryTreePaths(TreeNode* root) {
    stack<pair<TreeNode*, string>> st;
    vector<string> ret;
    st.push({root, to_string(root->val)});
    while(!st.empty()){
        TreeNode *node = st.top().first;;
        string curr = st.top().second;
        st.pop();
        
        if (node->left)
            st.push({node->left, curr + "->" + to_string(node->left->val)});
        
        if (node->right)
            st.push({node->right, curr + "->" + to_string(node->right->val)});
        
        if (!node->right && !node->left)
            ret.push_back(curr);
    }
    return ret;
}

int main(){

    TreeNode* n21 = new TreeNode(5);
    TreeNode* n11 = new TreeNode(2, nullptr, n21);
    TreeNode* n12 = new TreeNode(3);
    TreeNode* n00 = new TreeNode(1, n11, n12);
    
    auto it = binaryTreePaths(n00);
    for(auto&i:it) cout << i << '\n';

    return 0;
}