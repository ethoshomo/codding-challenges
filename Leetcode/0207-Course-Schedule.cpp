/* 207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 
Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
    A ideia subjacente ao problema é encontrar uma linha
    lógica de prerequisitos que seja suficiente para gerar
    um grafo sem ciclos. Se o grafo possuir ciclos, significa
    que estaremos diante de uma situação indesejada.
    
    Exemplo 1: [[0,1],[1,2],[2,0]]
    Zero depende de 1, que depende de 2, que depende de zero.
    0->1->2->0 => ciclo => Retorno falso. 

    Exemplo2: [[1,4],[2,4],[3,1],[3,2]]
    Um e dois dependem do quatro
    1,2 -> 4  
    
    Três depende do 1 e 2. 
    3 -> 1,2

    Logo:
    3 -> 1,2 -> 4 (ordem de dependência) ou
    4 -> 1,2 -> 3 (ordem direta de cursar).
    => não tem ciclo => retorno verdadeiro

*/
bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    // ciclo encontrado
    if (visited[node] == 1) return true;  

    // já visitado antes, sem problemas
    if (visited[node] == 2) return false; 

    // marcar como "visitando" ou "em visita"
    visited[node] = 1; 

    // Percorrer vizinhos
    for (int neighbor : graph[node])
        // ciclo detectado
        if (dfs(neighbor, graph, visited)) return true; 

    // marcar como "visitado"
    visited[node] = 2; 
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto& p : prerequisites)
        // criar aresta b -> a
        graph[p[1]].push_back(p[0]); 

    vector<int> visited(numCourses, 0);

    for (int i = 0; i < numCourses; ++i)
        // se detectar ciclo, retorna falso
        if (dfs(i, graph, visited)) return false; 

    // não tem ciclo, retorna verdadeiro
    return true; 
}


int main(){

    int numCourses = 2;
    vector<vector<int>> p = {{1,0},{0,1}};

    cout << (canFinish(numCourses, p) ? "SIM" : "NAO");
    return 0;
}