/* 138. Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Constraints:
0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
};

Node* helper(Node* node, int v, Node* n, Node* r, unordered_map<Node*, Node*>& m){
    
    if(m.count(node) != 0) return m[node];

    Node* aux = new Node(v);
    m[node] = aux;

    aux->next = n ? 
        helper(n, n->val, n->next, n->random, m)
        : 
        nullptr;

    aux->random = r ? 
        helper(r, r->val, r->next, r->random, m)
        : 
        nullptr;
    
    return aux;
}

Node* copyRandomList(Node* head) {
    if(!head) return head;
    unordered_map<Node*, Node*> map;
    return helper(head, head->val, head->next, head->random, map);
}

int main(){
    
    Node* n5 = new Node(1);
    Node* n4 = new Node(10);
    Node* n3 = new Node(11);
    Node* n2 = new Node(13);
    Node* n1 = new Node(7);

    n1->next = n2;
    n1->random = nullptr;
    n2->next = n3;
    n2->random = n1;
    n3->next = n4;
    n3->random = n5;
    n4->next = n5;
    n4->random = n3;
    n5->next = nullptr;
    n5->random = n1;

    auto it = copyRandomList(n1);

    while(it){
        cout << "("<< it->val << ',' << (it->random? to_string(it->random->val) : "NULL")<<")\n";
        it = it->next;
    }

    return 0;
}