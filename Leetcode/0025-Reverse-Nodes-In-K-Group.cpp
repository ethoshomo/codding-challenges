/*
25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 
Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 
Follow-up: Can you solve the problem in O(1) extra memory space?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    
    vector<ListNode*> nodes;
    auto it = head;

    while(it){
        nodes.push_back(it);
        it = it->next;
    }

    int n = nodes.size();
    for(int i = 0; i < n; i+=k){
        if(i+k-1 < n){
            cout << i << ' ' << i+k << '\n';
            reverse(nodes.begin()+i, nodes.begin()+i+k-1);
        }
    }

    nodes.push_back(nullptr);

    for(int i = 0; i < n; i++)
        nodes[i]->next = nodes[i+1];

    return nodes[0];
}

int main(){

    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);
    int k = 3;

    auto it = reverseKGroup(n1, k);

    while(it){
        cout << it->val << " ";
        it = it->next;
    }

    return 0;
}