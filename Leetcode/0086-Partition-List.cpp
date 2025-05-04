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

ListNode* partition(ListNode* head, int x) {
    vector<ListNode*> r;
    vector<ListNode*> nodes;

    ListNode* h = head;
    while(h){
        nodes.push_back(h);
        h = h->next;
    }

    int n = nodes.size();
    for(int i = 0; i < n; i++)
        if(nodes[i]->val < x)
            r.push_back(nodes[i]);

    for(int i = 0; i < n; i++)
        if(nodes[i]->val >= x)
            r.push_back(nodes[i]);

    r.push_back(nullptr);

    for(int i = 0; i < n; i++)
        r[i]->next = r[i+1];

    return r[0];
}

int main(){

    ListNode* n6 = new ListNode(2);
    ListNode* n5 = new ListNode(5, n6);
    ListNode* n4 = new ListNode(2, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(4, n3);
    ListNode* n1 = new ListNode(1, n2);
    int x = 3;

    auto it = partition(n1, x);

    while(it){
        cout << it->val << " ";
        it = it->next;
    }

    return 0;
}