/*297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/
#include <iostream>
#include <deque>
#include <regex>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(TreeNode* r){
    if(!r) return;
    cout<< r->val << ' ';
    print(r->left);
    print(r->right);
}

string serialize(TreeNode* root) {
    
    string ans = "";
    TreeNode* aux;
    deque<TreeNode*> r;

    r.push_back(root);

    while(!r.empty()){
        aux = r.front(); 
        r.pop_front();

        if(aux){
            r.push_back(aux->left);
            r.push_back(aux->right);
            ans += to_string(aux->val)+",";
        }
        else 
            ans += "NULL,";
    }

    ans.pop_back();

    return ans;
}

TreeNode* deserialize(string data) {
    if (data == "NULL") return nullptr;

    vector<string> d; 
    regex pattern("[^,]+");
    sregex_iterator it(data.begin(), data.end(), pattern);
    sregex_iterator end;
    
    while(it != end){
        d.push_back(it->str());
        ++it;
    }

    int i = 0;
    TreeNode* root = new TreeNode(stoi(d[i++]));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty() && i < d.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (d[i] != "NULL") {
            curr->left = new TreeNode(stoi(d[i]));
            q.push(curr->left);
        }
        i++;

        if (i < d.size() && d[i] != "NULL") {
            curr->right = new TreeNode(stoi(d[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main(){

    TreeNode* n21 = new TreeNode(4);
    TreeNode* n22 = new TreeNode(5);
    TreeNode* n11 = new TreeNode(2);
    TreeNode* n12 = new TreeNode(3, n21, n22);
    TreeNode* n00 = new TreeNode(1, n11, n12);

    auto s1 = serialize(n00);
    cout << s1 << '\n';

    auto s2 = deserialize(s1);
    print(s2);

    return 0;
}