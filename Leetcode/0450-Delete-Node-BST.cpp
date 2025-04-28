/* 450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []

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

TreeNode* deleteNode(TreeNode* r, int key) {
    if (!r) return nullptr;

    // Se o nó corrente é maior que a chave, vamos procurar na subárvore esquerda
    if (r->val > key) {
        r->left = deleteNode(r->left, key);
    }
    // Se o nó corrente é menor que a chave, vamos procurar na subárvore direita
    else if (r->val < key) {
        r->right = deleteNode(r->right, key);
    }
    // Se encontramos o nó com a chave
    else {
        // Caso 1: nó sem filhos
        if (!r->left && !r->right) {
            delete r; // Libera a memória
            return nullptr;
        }
        // Caso 2: nó com um filho
        else if (!r->left) {
            TreeNode* temp = r->right;
            delete r; // Libera a memória
            return temp;
        }
        else if (!r->right) {
            TreeNode* temp = r->left;
            delete r; // Libera a memória
            return temp;
        }
        // Caso 3: nó com dois filhos
        else {
            // Encontrar o sucessor (menor valor da subárvore direita)
            // Esse valor serve como raiz da subárvore.
            TreeNode* succ = r->right;
            while (succ && succ->left) succ = succ->left;

            // Substituir o valor do nó pelo sucessor
            r->val = succ->val;
            
            // Remover o sucessor da subárvore direita
            r->right = deleteNode(r->right, succ->val);
        }
    }
    return r;
}

int main(){

    TreeNode *l21 = new TreeNode(2);
    TreeNode *l22 = new TreeNode(4);
    TreeNode *l23 = new TreeNode(7);
    TreeNode *l11 = new TreeNode(3, l21, l22);
    TreeNode *l12 = new TreeNode(6, nullptr, l23);
    TreeNode *root = new TreeNode(5, l11, l12);

    cout << deleteNode(root, 6);

    return 0;
}