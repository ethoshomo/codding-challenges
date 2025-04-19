/* PRODUCT EXCEPT SELF

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
    A lógica do algoritmo abaixo é acumular todos os valores,
    exceto a posição atual (que se atribui 1).

    Assim, no movimento progressivo, nós sempre acumulamos
    para a próxima posição a multiplicação referente a posição
    anterior. Isto é, na posição zero, usamos 1 como valor e
    guardamos a multiplicação de 1 pelo valor contido na posição
    0. Na posição 2, usamos 1*v[0], e guardamos o acumulado para
    a posição 2, com o acumulado na posição 1 (1*v[0]*v[1]). Ou
    seja, nunca acumulamos o valor atual. 

    O movimento regressivo faz a mesma coisa, porém, acumulando
    as multiplicações posteriores. De modo que, na multiplicação
    da resposta, o encontro é o valor acumulado da multiplicação
    do anterior pelo acumulado da multiplicação do posterior, em 
    ambos os casos, sem o elemento atual.

*/
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int n1 = n-1;
    vector<int> a(n, 1);

    int pE = 1, pD = 1;
    for(int i = 0; i <= n-1; i++){
        a[i] *= pE;
        a[n1] *= pD;
        pE *= nums[i];
        pD *= nums[n1--];
    }

    return a;
}

int main(){

    vector<int> v = {1,2,3,4};
    vector<int> ans1 = productExceptSelf(v);
    for(auto a: ans1) cout << a << ' ';

    return 0;
}