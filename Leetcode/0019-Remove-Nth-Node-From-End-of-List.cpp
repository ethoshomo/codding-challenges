/*19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 
Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Follow up: Could you do this in one pass?
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* VERSÃO REFERÊNCIA DO LEETCODE - MAIS LENTA E MAIS COMPLEXA */
ListNode* removeNthFromEnd_complex(ListNode* head, int n) {

    int len=0;
    ListNode *temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    if(len==n){
        head=head->next;
        return head;
    }
    temp=head;
    for(int i=1;i<(len-n);i++){
        temp=temp->next;
    }
    
    temp->next=temp->next->next;
    return head;

}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    ListNode* fake_head = new ListNode(-1, head);
    auto right = head;
    auto left = fake_head;

    while(right){
        if(n > 0){
            n--;
            right = right->next;
        }
        else{
            right = right->next;
            left = left->next;
        }
    }

    left->next = left->next->next;

    return fake_head->next;
}

int main(){

    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);

    auto it = removeNthFromEnd(n1, 2);   

    while(it){
        cout << it->val << ' ';
        it = it->next;
    }

    return 0;
}