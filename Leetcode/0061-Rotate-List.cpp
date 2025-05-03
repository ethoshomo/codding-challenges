/* 61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    
    if(!head) return nullptr;

    vector<ListNode*> h;
    auto aux = head;
    while(aux){
        h.push_back(aux);
        aux = aux->next;
    }

    int hsz = h.size();
    vector<ListNode*> new_list(hsz+1, nullptr);
    int idx = 0;
    for(int i = 0; i < hsz; i++){
        idx = (i + k) % hsz;
        new_list[idx] = h[i];
    }

    for(int i = 0; i < hsz; i++)
        new_list[i]->next = new_list[i+1];

    head = new_list[0];

    return head;
}

int main(){

    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);
    int k = 2;

    auto it = rotateRight(n1, k);

    while(it){
        cout << it->val << ' ';
        it = it->next;
    }

    return 0;
}