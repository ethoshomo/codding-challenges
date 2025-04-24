#include <iostream>
#include <vector>
#include <numeric> 
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

/////////////////////////////////////////// DFS
void helper(TreeNode* a, vector<vector<double>>& r, int l){
    
    if(static_cast<int>(r.size()) <= l) r.resize(l+1);

    if(!a->left && !a->right) {
        r[l].push_back(a->val);
        return;
    }

    r[l].push_back(a->val);
    helper(a->left, r, l+1);
    if(a->right) helper(a->right, r, l+1);
}

vector<double> averageOfLevels_dfs(TreeNode* root) {
    vector<vector<double>> r;
    vector<double> result;
    helper(root, r, 0);

    for(size_t i = 0; i < r.size(); i++){
        int total = accumulate(r[i].begin(), r[i].end(), 0);
        result.push_back(total*1.0/r[i].size());
    }

    return result;
}


/////////////////////////////////////////// BFS
// Essa versão é executou 4x mais rápido
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> r;
    TreeNode* aux = nullptr;
    deque<TreeNode*> d;
    d.push_back(root);

    while(!d.empty()){
        double sum = 0;
        int n = d.size();
        for(int i = 0; i < n; i++){
            aux = d.front();
            d.pop_front();
            sum += aux->val;
            if(aux->left) d.push_back(aux->left);
            if(aux->right) d.push_back(aux->right);
        }
        r.push_back(sum*1.0/n);
    }

    return r;
}

int main(){

    TreeNode* l21 = new TreeNode(15);
    TreeNode* l22 = new TreeNode(7);
    TreeNode* l11 = new TreeNode(9,l21, l22);
    TreeNode* l12 = new TreeNode(20);
    TreeNode* root = new TreeNode(3, l11, l12);

    auto r = averageOfLevels(root);

    for(auto c: r) cout << c << ' ';

    return 0;
}