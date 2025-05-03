/* 143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 
Constraints:
The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList_slowly(ListNode* head) {
    if(!head->next || !head->next->next) return;

    // a->b => b<key> : a<value>
    unordered_map<ListNode*, ListNode*> map;

    // f at head
    ListNode* f = head;
        
    // l at index 1
    ListNode* l = head->next;
    
    // r at end
    ListNode* r = head;
    while(r->next){
        map[r->next] = r;
        r = r->next;
    }

    int i = 0;
    while(l != r){
        // odd: L_1, L_2, ..
        if(i & 1){
            f->next = l;
            f = l;
            l = l->next;
        }
        // even: L_n, L_n-1, ..
        else{
            f->next = r;
            f = r;
            r = map[r];
        }
        i++;
    }

    // Last one
    if(i & 1){
        f->next = l;
        f = l;
    }
    else{
        f->next = r;
        f = r;
    }
    f->next = nullptr;

}

// Ótima opção para ter controle dos indices
void reorderList(ListNode* head) {
    vector<ListNode*> nodes;

    // mapping
    auto aux = head;
    while(aux){
        nodes.push_back(aux);
        aux = aux->next;
    }

    int i = 0, j = nodes.size()-1;
    while(i < j){
        nodes[i]->next = nodes[j];
        i++;
        if(i == j) break;
        nodes[j]->next = nodes[i];
        j--;
    }
    nodes[i]->next = nullptr;
}

int main(){

    ListNode* n4 = new ListNode(4);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);

    reorderList(n1);

    auto it = n1;

    while(it){
        cout << it->val << ' ';
        it = it->next;
    }

    return 0;
}
