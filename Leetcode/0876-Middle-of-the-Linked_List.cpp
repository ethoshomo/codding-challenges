/*
876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
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

ListNode* middleNode(ListNode* head) {

    ListNode* aux = head;

    int i = 0;
    while(head){
        if(i & 1) aux = aux->next;
        head = head->next;
        i++;
    }

    if(i&0) aux = aux->next;

    return aux;
}

int main(){

    ListNode* n6 = new ListNode(6);
    ListNode* n5 = new ListNode(5,n6);
    ListNode* n4 = new ListNode(4,n5);
    ListNode* n3 = new ListNode(3,n4);
    ListNode* n2 = new ListNode(2,n3);
    ListNode* n1 = new ListNode(1,n2);

    auto result = middleNode(n1);

    cout << result->val;

    return 0;
}