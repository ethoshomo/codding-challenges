/* 402. Remove K Digits

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

Constraints:
1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/
#include <iostream>
#include <string>

using namespace std;

/*
    O algoritmo abaixo é relacionado com a eliminação de
    digitos mais significativos deixando sempre os menores.

    Isto é, usa-se uma string como se fosse uma stack. 
    Assim, ao percorrer o número fornecido, a gente verifica
    se o próximo número é menor. Isso potencialmente traz
    um valor menor. Isso acontece até que o número de remoções
    máximo seja atingido. Caso se chegue ao final, e ainda
    se possa fazer remoções, eliminamos os digitos mais
    significativos à esquerda. Por exemplo:

    num = 1432219
    remoções = 3

    Iteração i = 0:
    num = "1" 432219
    stack = 1
    r = 3
    
    Iteração i = 1:
    num = 1 "4" 32219
    stack = 14
    r = 3

    Iteração i = 2:
    num = 14 "3" 2219
    stack = 13
    r = 2

    Iteração i = 3:
    num = 143 "2" 219
    stack = 12
    r = 1

    Iteração i = 4:
    num = 1432 "2" 19
    stack = 122
    r = 1

    Iteração i = 4:
    num = 14322 "1" 9
    stack = 121
    r = 0

    Iteração i = 4:
    num = 143221 "9"
    stack = 1219
    r = 0

    Resposta final: 1219.

*/
string removeKdigits(string num, int k) {
    string stack;

    for (char digit : num) {
        while (!stack.empty() && k > 0 && stack.back() > digit) {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }

    // Se ainda tem dígitos para remover, remova do final
    while (k > 0 && !stack.empty()) {
        stack.pop_back();
        k--;
    }

    // Remover zeros à esquerda
    int i = 0;
    while (i < stack.size() && stack[i] == '0') i++;
    string result = stack.substr(i);

    return result.empty() ? "0" : result;
}

int main(){

    string s = "1432219";
    int k = 3;

    cout << removeKdigits(s, k);
    return 0;
}