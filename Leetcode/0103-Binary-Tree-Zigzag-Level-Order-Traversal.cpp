#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;

    // Precisa percorrer BFS: linha par (esquerda->direita) linha inversa (direita->esquerda)
    deque<TreeNode*> d;
    d.push_back(root);

    while(!d.empty()){

    }

    return result;
}

int main(){
    TreeNode* n21 = new TreeNode(15);
    TreeNode* n22 = new TreeNode(7);
    TreeNode* n11 = new TreeNode(9);
    TreeNode* n12 = new TreeNode(20, n21, n22);
    TreeNode* n00 = new TreeNode(3, n11, n12);

    auto it = zigzagLevelOrder(n00);

    for(auto & i :it){
        for(auto & c : i){
            cout << c << ' ';
        }
        cout <<'\n';
    }
    return 0;
}