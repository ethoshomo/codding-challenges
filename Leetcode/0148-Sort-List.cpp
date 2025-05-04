/* 148. Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
 
Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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

ListNode* sortList(ListNode* head) {

    vector<ListNode*> v;

    auto it = head;
    while(it){
        v.push_back(it);
        it = it->next;
    }

    sort(v.begin(), v.end(), [](ListNode* a, ListNode*b){
        return a->val < b->val;
    });

    v.push_back(nullptr);

    for(size_t i = 0; i < v.size()-1; i++)
        v[i]->next = v[i+1];
    
    return  v[0];
}

int main(){

    ListNode* n4 = new ListNode(3);
    ListNode* n3 = new ListNode(1, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(4, n2);

    auto it = sortList(n1);

    while(it){
        cout << it->val << " ";
        it = it->next;
    }

    return 0;
}