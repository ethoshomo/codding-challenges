/* 131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
 
Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <functional>

using namespace std;
/* 
    A função abaixo cria partições que são compostas apenas de
    palindromos. O problema é complexo e dificil de ser resolvido, 
    pois, precisamos identificar as partições que apenas permitem
    elementos na forma de palindromos. Por exemplo: 
    input:  "aab"
    output: [["a","a","b"],["aa","b"]]

    A ideia do algoritmo abaixo é construir uma tabela de memoização
    com as combinações possíveis de caracteres que sejam palindromos. 
    Por exemplo: todos os elementos i = j são elementos unitários: 
    (0,0) = 'a'; (1,1) = 'a'; (2,2) = 'b'. Os demais casos são 
    combinações ('aa' e 'ab').
        |   | a | a | b |
        | a | T | T | F |
        | a |   | T | F |
        | b |   |   | T |
    
    Essa tabela evitar ter que ficar verificando se a substring é 
    ou não um palindromo, facilitando as contas. 


    A segunda parte do algoritmo trata-se de um backtracking para 
    fazer as combinações possíveis. 
    
    A primeira parte do backtracking é a condição de parada, que 
    ficou delimitada para quando o start fosse do tamanho da string 
    de entrada. Nesse momento, coletamos a partição atual com a
    configuração acumulada na recursão (isso será desfeito ao 
    retornar para a posição inicial).  

    Pois bem, a segunda parte é relacionada com eventuais partições 
    que podem ser obtidas a partir das recursões. Isto é: 

    string = 'aab'
    start = 0;

    end = start = 0
    valores possíveis de end: 0,1,2 -> percorre todos os valores. 

    Exemplo: start = 0, end = 1.
    dp[start][end] -> 
        dp[0][1] (true): adiciona 'aa'
                         backtranking(1) -> 
                                dp[1][1] (true): adiciona 'a'
                                                 backtracking(2) -> 
                                                    d[2][2] (true) -> adiciona 'b'
                                                                      backtraking(3) ->
                                                                        condição de parada.
                                                                        adiciona ['aa','a','a']
                                                                        nos resultados.
                                dp[1][2] (false): nem entra no if. 

    Ao final, serão geradas todas as combinações possíveis. 
*/
vector<vector<string>> partition(string s) {

    vector<vector<string>> result;
    vector<string> current_partition;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
            }
        }
    }

    function<void(int)> backtrack = [&](int start) {
        if (start == s.size()) {
            result.push_back(current_partition);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (dp[start][end]) {
                current_partition.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1);
                current_partition.pop_back();
            }
        }
    };

    backtrack(0);
    return result;
}


int main(){
    string s = "aab"; // Esperado: [[a,a,a],[a,b]]

    auto it = partition(s);

    for(auto i: it){
        for(auto e: i){
            cout << e << ' ';
        }
        cout << '\n';
    }

    return 0;
}