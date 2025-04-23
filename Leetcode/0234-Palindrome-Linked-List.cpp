/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 
Follow up: Could you do it in O(n) time and O(1) space?
*/
#include <iostream>
#include <map>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

bool isPalindrome_map(ListNode* head) {
    
    if(!head) return false;

    ListNode* start = head;
    ListNode* end = head;
    map<ListNode*, ListNode*> getBack;

    // Posiciona no último e coleta volta.
    while(end->next){
        getBack[end->next] = end;
        end = end->next;
    }

    while(true){
        if(start->val != end->val) return false;
        start = start->next;
        end = getBack[end];
        if(start == end || end->next == start) break;
    }

    return true;
}


bool isPalindrome(ListNode* head) {
    
    if(!head) return false;

    ListNode* aux = head;
    vector<int> values;

    while(aux){
        values.push_back(aux->val);
        aux = aux->next;
    }

    int l = 0, r = values.size()-1;
    while(l <= r && values[l] == values[r]) {l++; r++;}

    return l >= r;
}

int main(){

    ListNode* n4 = new ListNode(1);
    ListNode* n3 = new ListNode(2, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);
    
    cout << isPalindrome(n1) ? "TRUE" : "FALSE";

    return 0;
}