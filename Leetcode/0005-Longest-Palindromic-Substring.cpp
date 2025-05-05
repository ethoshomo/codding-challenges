/*5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/
#include <iostream>
#include <vector>

using namespace std;

// Minha versão (beats 92.82%) - O(n²) - mais simples
// Segue o algoritmo Center Expansion
string longestPalindrome_(string s)
{

    int f = 0;
    int n = s.size();
    int refL = 0, refR = 0;
    int refMax = 0, tam = 0;
    while (f < n)
    {

        // Check type xyx
        tam = 1;
        while (f - tam >= 0 && f + tam < n && s[f - tam] == s[f + tam])
            tam++;
        tam--;
        if (2 * tam + 1 > refMax)
        {
            refMax = 2 * tam + 1;
            refL = f - tam;
            refR = f + tam + 1;
        }

        // Check type xyyx
        if (f + 1 < n && s[f] == s[f + 1])
        {
            tam = 1;
            while (f - tam >= 0 && f + tam + 1 < n && s[f - tam] == s[f + tam + 1])
                tam++;
            tam--;
            if (2 * tam + 2 > refMax)
            {
                refMax = 2 * tam + 2;
                refL = f - tam;
                refR = f + tam + 2;
            }
        }
        f++;
    }
    return string(s.begin() + refL, s.begin() + refR);
}

/* Manachers Algorithm - mais eficiente - O(n) - Beats 89.75% ?!?! */
string longestPalindrome(const string &s){
    if (s.empty())
        return "";

    // 1. Pré-processamento: insere separadores e sentinelas
    string t = "^";
    for (char c : s)
        t += "#" + string(1, c);
    t += "#$"; // $ evita checagem de limite no final

    int n = t.length();
    vector<int> p(n, 0);       // p[i] = raio do palíndromo centrado em i
    int center = 0, right = 0; // centro e limite direito do maior palíndromo atual
    int maxLen = 0, centerIndex = 0;
    int mirror = 0;

    for (int i = 1; i < n - 1; ++i){
        mirror = 2 * center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        // Tenta expandir em torno de i
        while (t[i + p[i] + 1] == t[i - p[i] - 1])
            ++p[i];

        // Atualiza centro e limite direito, se expandiu além de right
        if (i + p[i] > right){
            center = i;
            right = i + p[i];
        }

        // Atualiza o maior palíndromo encontrado
        if (p[i] > maxLen){
            maxLen = p[i];
            centerIndex = i;
        }
    }

    // 3. Extrai o palíndromo da string original
    int start = (centerIndex - maxLen) / 2; // mapeia posição em t de volta para s
    return s.substr(start, maxLen);
}

int main(){
    // string str = "babad";
    // string str = "cbbd";
    // string str = "brsallastad";
    string str = "brsalastad";

    cout << longestPalindrome(str);

    return 0;
}