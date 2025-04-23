/*141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
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

// Testei map e unordered map. Map foi mais rápido,
// embora sua adição seja O(logn) e em unordered map
// seja O(1).
bool hasCycle_high_memory(ListNode *head) {

    map<ListNode*,int> m;
    m[head] = 1;

    while(head){
        head = head->next;
        if(m.find(head) != m.end()) 
            return true;
        m[head] = 1;
    }
    return false;
}

// Supostamente era para rodar rápido, mas
// o método acima foi mais ligeiro.
bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
}

int main(){

    //ListNode* n4 = new ListNode(-4);
    //ListNode* n3 = new ListNode(0,n4);
    //ListNode* n2 = new ListNode(2,n3);
    ListNode* n1 = new ListNode(-1);
    //n4->next = n2;

    bool result = hasCycle(n1);

    cout << (result? "TRUE" : "FALSE");

    return 0;
}