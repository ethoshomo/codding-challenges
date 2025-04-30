#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    vector<Node *> neighbors;
    Node(){val = 0;neighbors = vector<Node *>();}
    Node(int _val){val = _val;neighbors = vector<Node *>();}
    Node(int _val, vector<Node *> _neighbors){val = _val;neighbors = _neighbors;}
};

// VERSÃO LENTA
/*
    Nessa versão existe uma criação dos nós
    para depois realizar a inserção dos vizinhos.
*/
Node* cloneGraph_(Node* node) {
    if(!node) return nullptr;
    if(node->neighbors.size() == 0) return new Node(node->val);

    deque<Node*> q;
    map<int, Node*> nodes;
    
    nodes[node->val] = new Node(node->val);
    q.push_back(node);
    
    // Primeira BFS: criar todos os nós
    while(!q.empty()) {
        Node* aux = q.front();
        q.pop_front();
        for(auto n : aux->neighbors) {
            if(nodes.find(n->val) == nodes.end()) {
                nodes[n->val] = new Node(n->val);
                q.push_back(n);
            }
        }
    }
    
    // Segunda BFS: conectar os vizinhos
    q.push_back(node);
    set<int> visited; // Para não visitar o mesmo nó duas vezes
    
    while(!q.empty()) {
        Node* aux = q.front();
        q.pop_front();
        
        if(visited.count(aux->val)) continue;
        visited.insert(aux->val);
        
        for(auto n : aux->neighbors) {
            nodes[aux->val]->neighbors.push_back(nodes[n->val]);
            q.push_back(n);
        }
    }

    return nodes[node->val];
}

// Versão rápida
// Se os nós não são encontrados na estrutura de dados de
// referência, eles serão criados para serem inseridos.
// Mas, se existirem, são inseridos mesmo assim.
Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> oldToNew;
    queue<Node*> q;

    q.push(node);
    oldToNew[node] = new Node(node->val);

    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        for (auto nei: cur->neighbors){
            if (oldToNew.count(nei) == 0){
                oldToNew[nei] = new Node(nei->val);
                q.push(nei);
            }
            oldToNew[cur]->neighbors.push_back(oldToNew[nei]);
        }
    }

    return oldToNew[node];
}

int main(){

    Node* n4 = new Node(4);
    Node* n3 = new Node(3);
    Node* n2 = new Node(2);
    Node* n1 = new Node(1);
    n1->neighbors = vector<Node*>{n2,n4};
    n2->neighbors = vector<Node*>{n1,n3};
    n3->neighbors = vector<Node*>{n2,n4};
    n4->neighbors = vector<Node*>{n1,n3};

    auto it = cloneGraph(n1);

    cout << it->val;

    return 0;
}