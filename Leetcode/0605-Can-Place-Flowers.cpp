/* 605. Can Place Flowers

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 
Constraints:
1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

*/
#include <iostream>
#include <vector>

using namespace std;

// Versão lenta
bool canPlaceFlowers_(vector<int> &flowerbed, int n){
    int n1 = flowerbed.size(), i = 0, zeros = 0, total = 0, sum = 0;

    // simula 0 antes do início
    if (flowerbed[0] == 0) zeros = 1;

    while (i < n1)
    {
        if (flowerbed[i] == 0)
            zeros += 1;
        else{

            if (zeros & 1)
                total += zeros / 2;
            else{
                sum = zeros / 2 - 1;
                if(sum > 0) total += sum;
            }
            zeros = 0;
        }
        i++;
    }

    // Simula 0 na última posição
    if (flowerbed[n1 - 1] == 0) zeros++;
    if (zeros > 0) 
        total += (zeros - 1) / 2;

    return total >= n;
}

// Versão rápida
bool canPlaceFlowers(vector<int>& flowerbed, int n){
    // Se não precisamos plantar nenhuma flor, retorna true imediatamente
    if (n == 0)
        return true;

    // Contador de zeros consecutivos (começa em 1 para simular um zero à esquerda da flowerbed)
    int seqCount = 1;

    // Percorre toda a flowerbed
    for (int i = 0; i < flowerbed.size(); i++) {

        if (flowerbed[i] == 1)
            // Se encontrar uma flor, zera a contagem de zeros consecutivos
            seqCount = 0;
        else
            // Se encontrar um espaço vazio, aumenta a contagem de zeros consecutivos
            seqCount++;

        if (seqCount == 3) {
            // Se tivermos 3 zeros consecutivos, podemos plantar 1 flor no meio
            // Exemplo: [0, 0, 0] → planta no centro → [0, 1, 0]

            n--;              // Plantamos uma flor
            seqCount = 1;     // Reinicia a contagem, mantendo o zero do final para próximo grupo
        }
    }

    // Após o loop, se o último espaço era zero e sobrou uma sequência [0, 0], 
    // podemos plantar uma última flor no final (porque simulamos um zero "depois" do array)
    if (flowerbed[flowerbed.size() - 1] == 0 && seqCount == 2)
        n--;

    // Se conseguimos plantar todas as flores necessárias, retorna true
    return (n <= 0);
}


int main()
{

    vector<int> v = {1, 0, 0, 0, 1};
    int n = 1;

    cout << (canPlaceFlowers(v, n) ? "TRUE" : "FALSE");
    return 0;
}