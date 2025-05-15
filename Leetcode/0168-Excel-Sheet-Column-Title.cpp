/* 168. Excel Sheet Column Title

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

Example 1:
Input: columnNumber = 1
Output: "A"

Example 2:
Input: columnNumber = 28
Output: "AB"

Example 3:
Input: columnNumber = 701
Output: "ZY"
 
Constraints:
1 <= columnNumber <= 231 - 1
*/
#include <iostream>

using namespace std;

/*
    Tem uma pegadinha nesse problema. Os valores
    são 1-indexados. Isso dá um problema de conta.
    Por exemplo: 1 - A, 2 - B, ... , 26 - Z, 
                 27 - AA ..

    Não tem 0 - A ou 27 - Vazio. Isso é meio
    descompassado com i%26 que considera o 0.
*/
string convertToTitle(int columnNumber) {

    string ans = "";
    while(columnNumber--){
        ans = static_cast<char>('A'+columnNumber%26) + ans;
        columnNumber /= 26;
    }

    return ans;
}

int main(){

    int n = 701;
    //int n = 28;
    //int n = 26;

    cout << convertToTitle(n);

    return 0;
}