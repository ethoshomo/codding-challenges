/*92. Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
 
Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 
Follow up: Could you do it in one pass?
*/

#include <iostream>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head) return nullptr;
    if(!head->next || left == right) return head;

    map<ListNode*, ListNode*> getBack;
    ListNode* l = head;
    ListNode* r = head;

    int counter = 1;
    while(l && counter < left){
        l = l->next;
        counter++;
    }
    
    counter = 1;
    while(r && counter < right){
        getBack[r->next] = r;
        r = r->next;
        counter++;
    }

    bool loop = true;
    while(loop){
        swap(l->val, r->val);
        l = l->next;
        r = getBack[r];    
        
        if(l == r || r->next == l)
            loop = false;
    }

    return head;       
}

// Versão mais eficiente do Leetcode
ListNode* reverseBetween_leetcode(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cut_left = dummy;

    // Step 1: Move to the node just before the `left`th node
    for (int i = 1; i < left; ++i) {
        cut_left = cut_left->next;
    }

    ListNode* start = cut_left->next;   //'start' points to the first node to reverse
    ListNode* curr = start;
    ListNode* prev = cut_left;

    // Step 2: Reverse `right - left + 1` nodes
    for (int i = 0; i < right - left + 1; ++i) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Step 3: Connect the reversed sublist back
    cut_left->next = prev;
    start->next = curr;

    ListNode* result = dummy->next;
    delete dummy;
    return result;
}


int main(){

    //ListNode* n5 = new ListNode(5);
    //ListNode* n4 = new ListNode(4, n5);
    //ListNode* n3 = new ListNode(3, n4);
    //ListNode* n2 = new ListNode(2, n3);
    //ListNode* n1 = new ListNode(1, n2);
    //int left = 2, right = 4;

    ListNode* n2 = new ListNode(5);
    ListNode* n1 = new ListNode(3, n2);
    int left = 1, right = 2;
    auto it = reverseBetween(n1, left, right);

    while(it){
        cout << it->val << ' ';
        it = it->next;
    }

    return 0;
}