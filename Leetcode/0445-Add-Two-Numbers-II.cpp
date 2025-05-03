/* 445. Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 
Follow up: Could you solve it without reversing the input lists?

*/
#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    // Reference
    auto n1 = l1;
    auto n2 = l2;
    
    // linked list: a->b   map: b->a
    unordered_map<ListNode*, ListNode*> map;
    
    // Posiciona ao final do numero 1
    while(n1->next){map[n1->next] = n1; n1 = n1->next;}

    // Posiciona ao final do numero 2
    while(n2->next){map[n2->next] = n2; n2 = n2->next;}

    // Sum
    ListNode* result = nullptr;
    bool overflow = false;
    int sum = 0, val1 = 0, val2 = 0;   
    while(n1 || n2 || overflow){
        
        n1 ? val1 = n1->val : val1 = 0;
        n2 ? val2 = n2->val : val2 = 0;
        
        sum = val1 + val2 + overflow;

        sum > 9 ? overflow = true: overflow = false;
    
        result = new ListNode(sum%10, result);

        map.count(n1) != 0 ? n1 = map[n1] : n1 = nullptr;
        map.count(n2) != 0 ? n2 = map[n2] : n2 = nullptr;
    }

    return result;
}

// Versão diferente: faz o reverse da linked list.
//ListNode* reverse(ListNode* head){
//    ListNode* nh=NULL,*t;
//    while(head){
//        t=head;
//        head=head->next;
//        t->next=nh;
//        nh=t;
//    }
//    return nh;
//}
//
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//    if(l1==NULL) return l2;
//    if(l2==NULL) return l1;
//    l1=reverse(l1);l2=reverse(l2);
//    ListNode *l3=NULL;
//    int c=0;
//    while(l1 || l2 || c){
//        int s=c;
//        if(l1){
//            s+=l1->val;
//            l1=l1->next;
//        }
//        if(l2){
//            s+=l2->val;
//            l2=l2->next;
//        }
//        c=s/10;
//        ListNode* t=new ListNode(s%10);
//        t->next=l3;
//        l3=t;
//    }
//    return l3;
//}

int main(){

    ListNode* l14 = new ListNode(3);
    ListNode* l13 = new ListNode(4, l14);
    ListNode* l12 = new ListNode(2, l13);
    ListNode* l11 = new ListNode(7, l12);
    
    ListNode* l23 = new ListNode(4);
    ListNode* l22 = new ListNode(6, l23);
    ListNode* l21 = new ListNode(5,l22);

    //ListNode* l11 = new ListNode(0);
    //ListNode* l21 = new ListNode(0);


    auto it = addTwoNumbers(l11, l21);

    while(it){
        cout<< it->val;
        it = it->next;
    }

    return 0;
}