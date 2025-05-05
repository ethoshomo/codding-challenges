/*72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Versão recursiva
int recursion(string w1, string w2, int i, int j, vector<vector<int>>& dp){
    int s1 = w1.size(), s2 = w2.size();
    if(i == s1) return s2 - j;
    if(j == s2) return s1 - i;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(w1[i] == w2[j])
        return dp[i][j] = recursion(w1,w2,i+1,j+1,dp);

    return dp[i][j] = 1 + min({
        recursion(w1, w2, i, j+1, dp),
        recursion(w1, w2, i+1, j, dp),
        recursion(w1, w2, i+1, j+1, dp)
    });

}

int minDistance_(string word1, string word2) {
    int m = max(word1.size(), word2.size());
    vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
    return recursion(word1, word2, 0, 0, dp);
}


// Versão iterativa - mais eficiente.
int minDistance(string word1, string word2) {
    
    // Montando memo: a tabela é montada de acordo com
    // as possibilidades de inserção (avanço de linhas) 
    // e deleção (avanço de colunas).
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // Inicialização 

    // word1 -> string "" (deletar todos caracteres)
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    
    // string "" -> word2 (inserir todos caracteres).
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    // Preenchimento da matriz
    //
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            if // Se caracteres iguais, não tem operação
            (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            
            else // Caso contrário,
                dp[i][j] = 1 + min({ 
                    dp[i-1][j],  // delete
                    dp[i][j-1],  // insert                 
                    dp[i-1][j-1] // replace
                }); 
        }
    }

    return dp[m][n];
}

int main(){
    string s1 = "intention";
    string s2 = "execution";

    cout << minDistance(s1, s2);

    return 0;
}

