/* 23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    if(k == 0) return nullptr;
    if(k == 1) return lists[0];
    
    vector<ListNode*> result;
    
    int minimum = 100000, idx = -2;
    while(idx != -1){

        minimum = 100000;
        idx = -1;
        for(size_t i = 0; i < lists.size(); i++){
            if(lists[i] && lists[i]->val < minimum){
                minimum = lists[i]->val;
                idx = i;
            }
        }

        if(idx != -1) {
            cout << lists[idx]->val << ' ';
            result.push_back(lists[idx]);
            lists[idx] = lists[idx]->next;
        }
    }

    result.push_back(nullptr);

    for(size_t i = 0; i < result.size()-1; i++)
        result[i]->next = result[i+1];

    return result[0];
}

int main(){

    ListNode* l13 = new ListNode(5);
    ListNode* l12 = new ListNode(4, l13);
    ListNode* l11 = new ListNode(1, l12);

    ListNode* l23 = new ListNode(4);
    ListNode* l22 = new ListNode(3, l23);
    ListNode* l21 = new ListNode(1, l22);

    ListNode* l32 = new ListNode(6);
    ListNode* l31 = new ListNode(2, l32);

    vector<ListNode*> v = {l11,l21, l31};
    
    auto it = mergeKLists(v);

    while(it){
        cout << it->val << ' ';
        it = it->next;
    }

    return 0;
}