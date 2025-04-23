/* 21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = nullptr;
    ListNode* aux = nullptr;

    if (list1 && list2) {
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
    } else if (list1)
        return list1;
    else
        return list2;
        
    aux = head;

    while (list1 != nullptr || list2 != nullptr) {
        if (list1 && list2) {
            if (list1->val < list2->val) {
                aux->next = list1;
                aux = list1;
                list1 = list1->next;
            } else {
                aux->next = list2;
                aux = list2;
                list2 = list2->next;
            }
        } else if (list1) {
            aux->next = list1;
            list1 = nullptr;
        } else if (list2) {
            aux->next = list2;
            list2 = nullptr;
        }
    }
    return head;
}

int main(){


    ListNode* n3 = new ListNode(4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);

    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(3, n4);
    ListNode* n6 = new ListNode(1, n5);

    auto r = mergeTwoLists(n1, n6);

    while(r != nullptr){
        cout << r->val << ' ';
        r = r->next;
    }

    return 0;
}