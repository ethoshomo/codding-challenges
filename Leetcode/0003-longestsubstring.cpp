/* 3-LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

/* MAX_SUBSTRING

    A ideia do algoritmo é criar um janelamento com dois ponteiros:
    um à esquerda e outro à direita, ambos inicialmente no índice 0.

    Note que valores distintos serão adicionados em um set desordenado.

    Com o aumento da janela (loop externo), podemos encontrar caractere 
    novo único na janela da string, e isso irá refletir em um aumento 
    da janela à direita e calculo do tamanho máximo de janela obtido. 
    
    No entanto, pode ser que o aumento traga um novo caractere que pode 
    conflitar com algum outro existente dentro da janela. Nesse caso, 
    iremos entrar em um while, que irá apagar o caractere mais a esquerda, 
    e iremos avançar o ponteiro da esquerda. Como reflexo, o tamanho da 
    janela irá diminuir até que seja encontrada uma nova forma substring 
    com caracteres únicos, mesmo que seja com ponteiros sobre o mesmo indice. 

    Nesse caso, o processo de expansão do janelamento pode ser retomado. 
    r
    pwwkew - max = 1
    l
     r
    pwwkew - max = 2
    l
      r
    pwwkew - max = 2
    l
      r
    pwwkew - max = 2
     l
      r
    pwwkew - max = 2
      l
       r
    pwwkew - max = 2
      l
        r
    pwwkew - max = 3
      l
         r
    pwwkew - max = 3
      l
         r
    pwwkew - max = 3
       l
          r
    pwwkew - max = 3 - encerra
       l
*/
long long max_substring(string s)
{

    unordered_set<char> chars;
    int left = 0, max_len = 0;

    for (int right = 0; right < (int)s.size(); right++)
    {

        // Se for constatada repetição, movemos a janela
        while (chars.count(s[right]))
        {
            chars.erase(s[left]);
            left++;
        }

        // Inserimos a letra mais a direita nos characteres
        chars.insert(s[right]);

        // Calculamos o tamanho do janelamento
        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main()
{

    string s = " ";

    cout << max_substring(s);

    return 0;
}