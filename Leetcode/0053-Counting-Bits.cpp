/* 338. Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

Constraints:
0 <= n <= 105
 
Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
*/

#include <iostream>
#include <vector>

using namespace std;

// Mais simples e tão eficiente quanto a programação dinâmica
vector<int> countBits_builtin(int n) {
    vector<int> r;

    for(int i = 0; i <= n; i++)
        r.push_back(__builtin_popcount(i));

    return r;
}

vector<int> countBits_bitmanipulation(int n) {
    vector<int> r;

    int total = 0;
    for(int mask = 0; mask <= n; mask++){
        total = 0;
        for(int power = 0; power < 32; power++)
            if((1 << power)& mask) total += 1;
        r.push_back(total);
    }
    return r;
}

// Programação dinâmica: mais eficiente
vector<int> countBits(int n) {
    vector<int> dp(n+1, 0);
    int offset = 1;

    for(int i = 1; i < n+1; i++){   
        if(2*offset == i) offset = i;
        dp[i] = 1 + dp[i-offset];
    }
    return dp;
}

int main(){

    vector<int> r = countBits(5);
    for(auto c: r) cout << c << ' ';

    return 0;
}

/* Explicação da programação dinâmica

TABELA DE ANÁLISE DE BITS (SISTEMA NUMÉRICO BINÁRIO)
    
BITS  NUMBER    2³  2²  2¹  2⁰      +
0000    0       0   0   0   0   0+0+0+0 = 0
0001    1       0   0   0   1   0+0+0+1 = 1 -> 2⁰
0010    2       0   0   1   0   0+0+2+0 = 2 -> 2¹
0011    3       0   0   1   1   0+0+2+1 = 3
0100    4       0   1   0   0   0+4+0+0 = 4 -> 2²
0101    5       0   1   0   1   0+4+0+1 = 5
0110    6       0   1   1   0   0+4+2+0 = 6
0111    7       0   1   1   1   0+4+2+1 = 7
1000    8       1   0   0   0   8+0+0+0 = 8 -> 2³

Reparar que a representação dos números é o somatório 
da multiplicação das potências de 2 com os 0s e 1s. Os
números das potencias de dois (1,2,4,8,16,...) estão
vinculados à posição dos 1s nas colunas. No digito menos
significativo (coluna 2⁰ ou zero), a combinação de zeros
e uns mostra apenas um único 1 na posição 0; no segundo
digito menos significativo, possui apenas um único 1 na
posição 1; na terceira, um único 1 na 3; e assim segue. 
Portanto, é possível usar operações para identificar 
combinações de presença e ausência. 

Além disso, existe um padrão de repetição. Por exemplo: 
considerando um único bit, existe uma oscilação entre 0 
e 1 - de modo que temos ums série: 

    {0,1,0,1,0,1,0,1, ...};

    - elemento 1: 0 (abre o ciclo)
    - elemento 2: 1 (fecha o ciclo)
    - elemento 3: reinicia o ciclo. 

Mas, se considerarmos 2:

    {00,01,10,11,00,01,10,11, ...}

    - elemento 1: 00 (abre o ciclo)
    - elemento 2: 01 
    - elemento 3: 10 
    - elemento 4: 11 (fecha o ciclo)
    - elemento 5: reinicia o ciclo. 

Os padrões irão se manifestar para quaisquer quantidades
de bits, mas é interessante notar que, para cada potencia
de 2, será adicionada uma coluna nova. Os valores
intermediários serão completados com as combinações
intermediárias. Isso explica, por exemplo, como as
combinações de programação dinâmica são formadas. 

É um pouco complicado, mas vamos lá. A cada potência
adicionamos uma coluna com o numero 1 e percebemos que
existe uma repetição dos padrões anteriores. 


    Primeira coluna: novo padrão 0 ou 1
    0 : 0: 0  = 0 -> base
    1 : 1: 2⁰ = 1
    
    Segunda Coluna: novo padrão 10, 11
    2: 10:  1 + dp[0] = 1 + 0 = 1
    3: 11:  1 + dp[1] = 1 + 1 = 2

    Terceira Coluna: novo padrão 100, 101, 110, 111
    4: 100: 1 + dp[0] = 1 + 0 = 1
    5: 101: 1 + dp[1] = 1 + 1 = 2
    6: 110: 1 + dp[10] = 1 + 1 = 2
    7: 111: 1 + dp[11] = 1 + 2 = 3

Podemos também generalizar a contagem com base na potencia
de dois atual (i-<potencia_atual>). Por exemplo: 
    dp[2] = 1+dp[2-2] = 1+dp[0]
    dp[3] = 1+dp[3-2] = 1+dp[1]
    dp[4] = 1+dp[4-4] = 1+dp[0]
    dp[5] = 1+dp[5-4] = 1+dp[1]
    dp[6] = 1+dp[6-4] = 1+dp[2]
    dp[7] = 1+dp[7-4] = 1+dp[3]
    dp[8] = 1+dp[8-8] = 1+dp[0]

Esse raciocínio permite a generalização de uma formula para
contar bits (em python): 

def countingBits(n): 
    dp = [0]*(n+1)
    offset = 1

    for i in range(1,n+1): 
        if offset*2 == i: 
            offset = i
        dp[i] = 1 + dp[i-offset]
    
    return dp
*/