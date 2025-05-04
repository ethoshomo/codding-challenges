/* 430. Flatten a Multilevel Doubly Linked List

You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

Example 1:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 2:
Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 3:
Input: head = []
Output: []
Explanation: There could be empty list in the input.

Constraints:
The number of Nodes will not exceed 1000.
1 <= Node.val <= 105

How the multilevel linked list is represented in test cases:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
             
The serialization of each level is as follows:
[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together, we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,    2,    3, 4, 5, 6, null]
             |
[null, null, 7,    8, 9, 10, null]
                   |
[            null, 11, 12, null]
Merging the serialization of each level and removing trailing nulls we obtain:
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
*/
#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node(int val_, Node *prev_ = nullptr, Node *next_ = nullptr, Node *child_ = nullptr)
        : val(val_), prev(prev_), next(next_), child(child_) {}
};

Node *helper(Node *head){
    
    Node *curr = head;
    Node *next = nullptr;
    Node *childHead = nullptr;
    Node *childTail = nullptr;
    Node *last = nullptr;

    while (curr){
        // Guarda o próximo nó
        next = curr->next; 

        // Flatten filho
        if (curr->child){
            
            // Salva filho
            childHead = curr->child;
            
            // Final do child
            childTail = helper(childHead); 

            // Conecta o child na posição correta na lista
            curr->next = childHead;
            childHead->prev = curr;
            curr->child = nullptr;

            // Se houver um próximo nó, conecta
            if (next){
                childTail->next = next;
                next->prev = childTail;
            }

            // O último nó agora é o tail do child
            last = childTail;
            
            // Move para o próximo nó
            curr = next;     
        }
        else{
            // Caso contrário, avança próximo nó
            last = curr;
            curr = curr->next;
        }
    }
    
    // Retorna o último nó da lista processada
    return last; 
}

Node *flatten(Node *head){
    if (!head)
        return nullptr;
    helper(head); // Chama o helper para fazer o flatten
    return head;  // Retorna a cabeça da lista
}

int main(){

    Node *n12 = new Node(12, nullptr, nullptr, nullptr);
    Node *n11 = new Node(11, nullptr, n12, nullptr);
    Node *n10 = new Node(10, nullptr, nullptr, nullptr);
    Node *n9 = new Node(9, nullptr, n10, nullptr);
    Node *n8 = new Node(8, nullptr, n9, n11);
    Node *n7 = new Node(7, nullptr, n8, nullptr);
    Node *n6 = new Node(6, nullptr, nullptr, nullptr);
    Node *n5 = new Node(5, nullptr, n6, nullptr);
    Node *n4 = new Node(4, nullptr, n5, nullptr);
    Node *n3 = new Node(3, nullptr, n4, n7);
    Node *n2 = new Node(2, nullptr, n3, nullptr);
    Node *n1 = new Node(1, nullptr, n2, nullptr);

    n2->prev = n2;
    n3->prev = n2;
    n4->prev = n3;
    n5->prev = n4;
    n6->prev = n5;
    n8->prev = n7;
    n9->prev = n8;
    n10->prev = n9;
    n12->prev = n11;

    auto it = flatten(n1);

    while (it){
        cout << it->val << ' ';
        it = it->next;
    }

    return 0;
}