#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//////////////// VERSÃO LENTA
void find_(TreeNode *root, vector<int> &q, int &m)
{
    if (!root)
        return;

    for (auto c : q)
        m = min(m, abs(root->val - c));
    q.push_back(root->val);

    if (root->left)
        find_(root->left, q, m);

    if (root->right)
        find_(root->right, q, m);
}

int getMinimumDifference_slow(TreeNode *root){
    vector<int> q;
    int m = 1000000;
    find_(root, q, m);
    return m;
}

/*
    A versão abaixo busca a diferença entre dois números
    explorando uma propriedade da árvore binária: a 
    travessia in order (esquerda, raiz, direita). Essa 
    ordem é importante porque gera uma lista de valores
    crescentes, de modo que dois números mais próximos 
    estarão necessariamente lado a lado na comparação. 

    Isso permite comparar os elementos pares a pares e
    obter o valor mínimo em tempo linear.
*/
int getMinimum(TreeNode *root, int &minDifference, int &prevValue){
    if (root == nullptr)
        return minDifference;

    getMinimum(root->left, minDifference, prevValue);

    if (prevValue >= 0)    {
        minDifference = min(minDifference, root->val - prevValue);
    }

    prevValue = root->val;

    getMinimum(root->right, minDifference, prevValue);

    return minDifference;
}

int getMinimumDifference(TreeNode *root){
    int minDifference = INT_MAX;
    int prevValue = -1;
    return getMinimum(root, minDifference, prevValue);
}

int main()
{

    TreeNode *l21 = new TreeNode(15);
    TreeNode *l22 = new TreeNode(7);
    TreeNode *l11 = new TreeNode(9);
    TreeNode *l12 = new TreeNode(20, l21, l22);
    TreeNode *root = new TreeNode(3, l11, l12);

    cout << getMinimumDifference(root);

    return 0;
}