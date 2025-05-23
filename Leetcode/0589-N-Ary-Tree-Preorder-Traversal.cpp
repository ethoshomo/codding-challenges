/* 589. N-ary Tree Preorder Traversal

Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

Constraints:
The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.

Follow up: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <vector>


using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {val = _val;}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void helper(Node* n, vector<int>& res){
    if(!n) return;
    res.push_back(n->val);
    for(auto c : n->children) 
        helper(c, res);
};

vector<int> preorder(Node* root) {
    vector<int> r;
    helper(root, r);
    return r;
}

int main(){
    Node* n21 = new Node(5);
    Node* n22 = new Node(6);
    Node* n11 = new Node(3, {n21, n22});
    Node* n12 = new Node(2);
    Node* n13 = new Node(4);
    Node* root = new Node(1, {n11, n12, n13});

    auto it = preorder(root);

    for(auto i: it) cout << i << ' ';
    return 0;
}