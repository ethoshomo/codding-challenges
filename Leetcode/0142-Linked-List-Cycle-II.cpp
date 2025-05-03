/*142. Linked List Cycle II

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 
Follow up: Can you solve it using O(1) (i.e. constant) memory?
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


// VERSÃO LENTA
ListNode *detectCycle_slow(ListNode *head) {
    auto it = head;

    unordered_map<ListNode*, int> map;

    int index = 0;
    map[it] = index++;

    while(it){
        if(it->next){
            if(map.count(it->next) == 0)
                map[it->next] = index++;
            else
                return it->next;
        }
        else{
            return nullptr;
        }
        it = it->next;
    }
    return nullptr;
}

/* VERSÃO OTIMIZADA - Tempo: O(n) e Espaço: O(1)

    Utiliza o algoritmo de Floyd ou Floyd Tortoise
    and Hare Algoithm para detecção de ciclos. 

    Primeiro ele utiliza os ponteiros 'f' (fast - 
    refere-se ao fato de que salta duas posições a
    cada rodada) e 's' (slow - refere-se ao fato de
    que salta apenas uma posição a cada rodada) para
    encontrar um ciclo. Se f == s, significa ciclo;
    mas, se o ponteiro rápido encontrar o nullptr,
    não haverá ciclo. 

    A segunda parte do algoritmo está relacionada
    com o fato de que não sabemos exatamente onde os
    ponteiros irão se encontrar. Por isso, não sabemos
    onde o ciclo se inicia e também precisamos de um
    terceiro ponteiro 't', que vai começar no início
    da lista. Nesse contexto, existe um correlação
    entre o número de nós até o início do ciclo (L), 
    o comprimento do ciclo (C) e a distância entre o
    inicio do ciclo e o ponto onde os ponteiros se
    encontraram (k). A ideia é que o ponteiro mais
    rápido percorre 2d enquanto que o lento percorre
    d. Assim, a diferença d deve necessariamente ser
    um múltiplo do comprimento do ciclo (C), o que
    garante que eles se encontrem dentro do ciclo. 
    Desse modo, se o ponteiro 't' começa no inicio
    da linked list, enquanto o 'f' está no ponto de
    encontro, e ambos avançando na mesma velocidade,
    eles se encontrarão no início do ciclo após L 
    passos de 't', visto que 'f' avança (k+(C-k))=C.

    Matematicamente:
    s = L+k     -- distância percorrida por 's'
    f = 2(L+k)  -- distância percorrida por 'f'
    f-s = L+k   -- diferença

    L+k = 0 (mod C)    -- ponto de encontro
    L = -k (mod C) 
      = C - K (mod C)  -- múltiplo de C

    t = L       -- distância até o inicio do ciclo
    se f == k, ele vai precisar de C-k para chegar
    ao inicio. Como L = C-k, então 'f' e 't' se 
    encontram no começo do ciclo. 

*/ 
ListNode *detectCycle(ListNode *head) {
    if(head == nullptr) 
        return 0;

    auto f = head, s = head, t = head;
    while(f->next && f->next->next){
        f = f->next->next;
        s = s->next;
        
        if(f == s){
            while(t != f) {
                f = f->next;
                t = t->next;
            }
            return f;
        }
    }
    return NULL;
}


int main(){

    ListNode* n4 = new ListNode(-4);
    ListNode* n3 = new ListNode(0, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(3, n2);
    n4->next = n2;

    cout << detectCycle(n1)->val;

    return 0;
}