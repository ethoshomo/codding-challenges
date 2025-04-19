/* 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* result = new ListNode();
    ListNode* head1 = l1;
    ListNode* head2 = l2;
    
    ListNode* r = result;
    int overflow = 0;
    while (head1 || head2 || overflow) {
        
        if(head1 && head2){
            r->val = head1->val + head2->val + overflow;
        }
        else if(head1 && !head2){
            r->val = head1->val + overflow;
        }
        else if(!head1 && head2){
            r->val = head2->val + overflow;
        }
        else{
            r->val += overflow;
        }

        overflow = 0;

        if (r->val > 9) {
            r->val = r->val % 10;
            overflow = 1;
        }
        if(head1)
            head1 = head1->next;
        if(head2)
            head2 = head2->next;

        if (head1 || head2 || overflow) {
            r->next = new ListNode();
            r = r->next;
        }
    }
    
    return result;
}

int main(){

    ListNode *s1= new ListNode (3);
    ListNode *s2= new ListNode (4, s1);
    ListNode *N1= new ListNode (2, s2);

    ListNode *t1 = new ListNode (4);
    ListNode *t2 = new ListNode (6, t1);
    ListNode *N2 = new ListNode (5, t2);

    ListNode *r = addTwoNumbers(N1,N2);

    while(r){
        cout << r->val;
        r = r->next;
    }

    return 0;
}