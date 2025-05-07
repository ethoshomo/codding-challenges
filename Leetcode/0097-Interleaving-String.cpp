/* 97. Interleaving String

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.

Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true

Constraints:
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 
Follow up: Could you solve it using only O(s2.length) additional memory space?
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    A ideia do algoritmo abaixo é montar uma tabela
    mais ou menos assim: 
    s1 = a b c
    s2 = d e f 
    s3 = a d b c e f

    Note que a tabela possui tamanho númerico adicionado  
    de +1 em cada dimensão para abrigar o caso base: "" + "".
    Todos os valores são inicializados em false (0), exceto 
    o caso dp[0][0], que é true (1).

    Tabela Inicial:
    i \ j   ""      d       de      def
    ""      1       0       0       0
    a       0       0       0       0
    ab      0       0       0       0
    abc     0       0       0       0

    A primeira linha analisa se conseguimos formar s3 usando
    total ou parcialmente os elementos de s2. Como a primeira
    letra de s3 é 'a'. Não vai combinar com 'd', 'de' e nem com
    'def'. Assim, todos os valores, exceto o primeiro, são 0. 

    Tabela Inicial:
    i \ j   ""      d       de      def
    ""      1       0       0       0
    a       1       1       0       0
    ab      0       0       0       0
    abc     0       0       0       0

    Na sequência, a linha indexada com 2 (linha de "ab") vai
    verificar se é possível combinar "ab" com 1 caractere
    da célula superior (note que o index dela é 1). Assim,
    verificamos que "ab" + ("a"+""+"") não gera s3 em nenhuma de
    suas combinações: aab, aba, baa. Mas, "ab"+"ad" pode gerar:
    "aba" e "abd", sendo está última OK. 
    
    Assim, segue o raciocínio até final da tabela.

    Primeira linha:

    i \ j   ""      d       e       f
    ""      1       0       0       0
    a       1       1       0       0
    b       0       1       0       0
    c       0       1       1       1

    Assim, verificamos que o caminho forma s3: 
    (""+"")(0,0)+"a"(1,0)+"d"(1,1)+"b"(2,1)+"c"(3,1)+"e"(3,2)+"f"(3,3)

*/
bool isInterleave(string s1, string s2, string s3) {
    // Verifica se tamanho s1+s2=s3
    int m = s1.size(), n = s2.size();
    if (m + n != (int)s3.size()) return false;

    // Cria vetor de simulação indice
    vector<bool> f(n + 1, false);
    f[0] = true;

    // Itera sobre s3
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            
            // Calcula indice atual de s3
            int k = i + j - 1;

            // Verifica se o caractere de s1 pode combinar com s3
            if (i) f[j] = f[j] && (s1[i - 1] == s3[k]);

            // Verifica se o caractere de s2 pode combinar com s3
            if (j) f[j] = f[j] || (s2[j - 1] == s3[k] && f[j - 1]);
        }
    }

    return f[n];
}

int main(){

    string s1 = "aabd";
    string s2 = "abdc";
    string s3 = "aabdbadc";

    cout << (isInterleave(s1, s2, s3) ? "TRUE" : "FALSE");
    return 0;
}

