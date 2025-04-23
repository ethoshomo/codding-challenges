/* 206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 
Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

*/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

ListNode* reverseList(ListNode* head) {
    if(!head) return head;

    ListNode* behind = head;
    ListNode* ahead = head;
    
    head = head->next;
    ahead = ahead->next;
    if(head) head = head->next;
    behind->next = nullptr;

    while(head){
        ahead->next = behind;
        behind = ahead;
        ahead = head;
        head = head->next;
    }

    if(ahead) 
        ahead->next = behind;
    else 
        return behind;

    return ahead;
}

int main(){

    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);

    auto it = reverseList(n1);

    while(it){
        cout << it->val << ' ';
        it = it->next;
    }

    return 0;
}