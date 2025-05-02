/* 75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 
Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/
#include <iostream>
#include <vector>

using namespace std;

// VERSÃO MAIS OTIMIZADA
void sortColors(vector<int>& nums) {
    vector<int>count(3, 0);

    for (int n : nums)
        count[n]++;

    int i = 0;
    while (count[0]-- > 0) nums[i++] = 0;
    while (count[1]-- > 0) nums[i++] = 1;
    while (count[2]-- > 0) nums[i++] = 2;
}

/*
    Esse algoritmo é o da Bandeira Holandesa (3 cores)
    A ideia dele é trabalhar com 3 ponteiros:
    
    - MID: ponteiro móvel que vai deslocar da esquerda
    para a direita (inicia na esquerda primeira posição). 

    - LOW: ponteiro posicionado na posição onde ficam os
    zeros (esquerda: primeira posição). 

    - HIGH: ponteiro posicionado na posição onde ficam os 
    dois (direita: última posição).

    A ideia é analisar o valor de MID. Se ele for 0,
    faz o swap com LOW e avança uma posição de LOW e
    de MID. Se for 2, faz o swap com HIGH e decresce 
    a posição HIGH uma unidade e aumenta MID em uma
    unidade. Caso seja 1, apenas aumenta a posição
    de MID em uma unidade. Assim que o MID ficar maior
    que o HIGH, significa que não haverá mais SWAP
    para fazer e o vetor estará ordenado.

*/
void sortColors_(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(mid <= high) {
        if(nums[mid] == 0)
            swap(nums[low++], nums[mid++]);
        else if(nums[mid] == 1)
            mid++;
        else
            swap(nums[mid], nums[high--]);
    }
}

int main(){

    vector<int> v = {2,1,2,2,1,0,0,0,1,2,0,2,1};

    sortColors(v);

    for(auto e: v)cout << e << ' ';

    return 0;
}