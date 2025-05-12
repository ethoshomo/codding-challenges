/* 496. Next Greater Element I

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

Constraints:
1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.

Follow up: Could you find an O(nums1.length + nums2.length) solution?
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* Time complexity - O(nums2.size())

A ideia do algoritmo é implementar uma pilha monotônica, isto é, a pilha
deve observar uma ordem monotônica (ou crescente ou decrescente). Isso é 
possível porque o empilhamento segue regras simples, que retornam respostas
rápidas. Por exemplo: podemos montar uma pilha monotonicamente crescente
adicionando sempre os maiores valores (em sentido progressivo) ou o menor 
valor (em sentido regressivo). Para encontrar valores de um lado ou de
outro, que sejam maiores ou menores, vai determinar a forma de percorrer 
a lista de valores, mas a técnica é a mesma. 

No caso do desafio, deveríamos encontrar o primeiro valor maior a direita. 
Naturalmente, a ideia era percorrer a lista de traz para frente de modo
a montar uma pilha monotonicamente crescente. Nesse caso, se estamos no
fim da lista, não existe nenhum elemento maior que o último (retorna -1); 
mas, se estamos em outra posição, precisamos comparar o valor atual com o
valor no topo da pilha. Se o valor em cima da pilha é maior, ele será o maior
valor para aquele número; mas, se ele for menor, não será referência para nenhum
outro que venha posteriormente. É por essa razão que desempilhamos todos os
valores que são menores que o atual. Algo do tipo: 

pilha: $ 7, 5, 4, 3
valores de entrada: [8,2,6,3,4,5,7]
Valor atual: 6 (já empilhamos 7,5,4,3).
No entanto, agora, desempilharemos o 3, 4 e 5, pois todos esses valores são 
menores que o 6 e não serão referência para o 2 e para o 8. Afinal, o maior 
valor do 2 é o 6. Quando chegarmos no 8, desempilharemos todos os valores da 
pilha, pois ele é o maior valor do conjunto de referência. Isso vai retornar
-1, pois não há elemento à direita maior que 8. 
*/
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> maximum(10001, -10);
    vector<int> ans;
    stack<int> actualMax;

    for(int i = nums2.size()-1; i >= 0; i--){
        while(!actualMax.empty() && nums2[i] > actualMax.top()) actualMax.pop();
        maximum[nums2[i]] = (actualMax.empty() ? -1 : actualMax.top());
        actualMax.push(nums2[i]);
    }
    
    for(int i = 0; i < nums1.size(); i++)
        ans.push_back(maximum[nums1[i]]);

    return ans;

}

int main(){

    vector<int> n1 = {4,1,2};
    vector<int> n2 = {1,3,4,2};

    auto it = nextGreaterElement(n1, n2);

    for(auto i: it) cout << i << ' ';

    return 0;
}