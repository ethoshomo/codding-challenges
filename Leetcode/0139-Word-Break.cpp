#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* VERSÃO MAIS OTIMIZADA - Tempo O(n*m*k) - Espaço O(n).

    A memoização construída serve para armazenar
    se um novo começo de palavra pode ser reconhecido
    no indice marcado. É importante mencionar que o
    caso base, indice 0, abriga o espaço em branco. 
    Por exemplo: [1, 0, 0, 0, 0, 0, 1, (...), N ]. A partir
    do caso base (verdadeiro), foi reconhecida uma
    palavra de [0..4] (["a","p","p","l","e"]) e uma nova palavra começou em
    [5..7] (["p", "e", "n"]) e assim por diante.
    
    O objetivo do loop externo é montar a string 's'
    combinando as palavras existentes em wordDict. A
    ideia principal é percorrer todos os comprimentos
    possíveis de 's' e tentar encaixar uma palavra 
    depois que percorre a posição i. Por exemplo: 

    s = "applepenapple"
    wordDict = {"apple", "pen"}
    
    0 1 2 3 4 5 6 7 8 9 10 11 12
    a p p l e p e n a p  p  l  e

    Quando i = 5: reconhece 'apple' [0,5)
    ("equal(w.begin(), w.end(), s.begin() + start)")
    Essa parte é otimizada para usar ponteiros de 
    comparação ao invés de criar novas substrings.

    Notar que o começo do palavra, em 0, precisa estar
    marcado como true na memoização para que a anotação 
    de true aconteça em 5 ("&& dp[start]").

    Depois, continua percorrendo até que 
    i = 8, quando reconhece "pen". Na sequência, 
    continua até que i = 13, quando reconhece
    novamente "apple". 

    Assim, depois de percorrer toda a string, 
    o retorno de dp[13] retorna true.
*/
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    int len = 0;
    int start = 0;

    for (int i = 1; i <= n; i++) {
        for (const string& w : wordDict) {
            len = w.length();
            start = i - len;

            if (start >= 0 && dp[start] && equal(w.begin(), w.end(), s.begin() + start)){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}


// Minha versão - Tempo: O(n.m.k) Espaço: O(n)
bool recursion(int start, string s, vector<string>& w, vector<int>& dp){
    if (start >= s.size()) return true;
    if (dp[start] != -1) return dp[start];

    for (const auto& c : w) {
        if (start + c.size() <= s.size() &&
            equal(c.begin(), c.end(), s.begin() + start) &&
            recursion(start + c.size(), s, w, dp)) {
            return dp[start] = true;
        }
    }

    return dp[start] = false;
}

bool wordBreak_(string s, vector<string>& wordDict) {
    
    vector<int> dp(s.size()+1, -1);

    sort(wordDict.begin(), wordDict.end(), [](string a, string b){
        return a > b;
    });
    
    return recursion(0, s, wordDict, dp);
}

int main(){

    string s = "leetcode";
    vector<string> dict = {"leet","code"};

    cout << (wordBreak(s,dict)? "TRUE" : "FALSE");

    return 0;
}