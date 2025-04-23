/* 203. Remove Linked List Elements

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
 
Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if(!head) return head;

    if(head->val == val && head->next == nullptr) 
        return nullptr;
    else if(head->val == val)
        while(head->next && head->val == val) 
            head = head->next;

    ListNode* ahead = head;
    ListNode* behind = nullptr;
    
    while(ahead){
        if(ahead->val == val){
            ahead = ahead->next;
            if(behind) behind->next = ahead;
        }
        else{
            behind = ahead;
            ahead = ahead->next;
        }
    }

    if(!behind && !ahead) return nullptr;

    return head;
}

using namespace std;

int main(){

    ListNode* n7 = new ListNode(6);
    ListNode* n6 = new ListNode(5, n7);
    ListNode* n5 = new ListNode(4, n6);
    ListNode* n4 = new ListNode(3, n5);
    ListNode* n3 = new ListNode(6, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);
    int val = 6;

    auto it = removeElements(n1, val);

    while(it){
        cout << it->val << ' ';
        it = it->next;
    }

    return 0;
}