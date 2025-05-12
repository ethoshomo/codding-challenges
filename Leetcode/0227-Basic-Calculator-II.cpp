#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stack>

using namespace std;

/* 
    O truque é operar com o operador anterior. 
    Se for soma ou subtração, acumula no total.
    Se for multiplicação e divisão, acumula no last.
*/
int calculate(string s) {
      
    int n = s.size(), total = 0, last = 0, num = 0;
    char op = '+';

    for (int i = 0; i < n; ++i) {
        char c = s[i];

        if (isdigit(c))
            num = num * 10 + (c - '0');

        // se for operador ou fim da string, resolve a operação anterior
        if ((!isdigit(c) && c != ' ') || i == n - 1) {
            if (op == '+') {
                total += last;
                last = num;
            } else if (op == '-') {
                total += last;
                last = -num;
            } else if (op == '*')
                last *= num;
            else if (op == '/')
                last /= num;

            op = c;     // atualiza o operador
            num = 0;    // zera o número acumulado
        }
    }

    return total + last;
}

int main(){

    string s = "3+2*2";

    cout << calculate(s);

    return 0;
}