/* 22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8
*/
#include <iostream>
#include <vector>

using namespace std;

/* 
    Esse problema não tem solução fácil ou boa. 

    Podemos usar métodos de backtracking (ideal) com
    complexidade O(C(n)*n), recursões de Catalan (memoizadas)
    com complexidade de O(C(n)*n) ou com inserção incremental
    O(C(n)*n²). E olha que esses são os melhores algoritmos.
    É por isso que os casos de testes são 1 <= n <= 8.

    A solução abaixo é uma construção inplace otimizada
    que utiliza set para evitar duplicações. 

*/
void backtrack(int open, int close, int max, string& current, vector<string>& result) {
    
    // Critério de parada: insere em result o resultado formado
    if (current.size() == max * 2) {
        result.push_back(current);
        return;
    }

    // Se o número de parenteses abertos são menores que o máximo,
    // podemos adicionar mais um e iniciar uma nova recursão,
    // mas precisamos desfazer para explorar outros casos.
    if (open < max) {
        current.push_back('(');
        backtrack(open + 1, close, max, current, result);
        current.pop_back(); // desfaz
    }

    // Nesse caso, testamos a quantidade de parenteses fechados.
    // Segue mesma lógica acima.
    if (close < open) {
        current.push_back(')');
        backtrack(open, close + 1, max, current, result);
        current.pop_back(); // desfaz
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    backtrack(0, 0, n, current, result);
    return result;
}


int main(){
    
    int n = 3;

    auto it = generateParenthesis(n);

    for(auto i : it) cout << i << '\n';

    return 0;
}