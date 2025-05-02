/* 229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

Follow up: Could you solve the problem in linear time and in O(1) space?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Atingiu 100% de tempo
vector<int> majorityElement_(vector<int>& nums) {
    int n = nums.size();
    int limit = n/3;
    vector<int> res;

    if(limit == 0) {
        for(int i = 0; i < n; i++){
            auto it = find(res.begin(), res.end(), nums[i]);
            if(it == res.end()) res.push_back(nums[i]);
        }
        return res;
    }

    int minimum = *min_element(nums.begin(), nums.end());
    int maximum = *max_element(nums.begin(), nums.end());

    vector<int> count(abs(maximum)+abs(minimum)+1, 0);
    
    
    for(int i = 0; i < n; i++){
        count[nums[i]+abs(minimum)]++;
    }

    n = count.size();
    for(int i = 0; i < n; i++)
        if(count[i] > limit){
            auto it = find(res.begin(), res.end(), i-minimum);
            if(it == res.end()) 
                res.push_back(i-abs(minimum));
        }
            
    return res;
}

/*
    ALGORITMO DE BOYER-MOORE MAJORITY VOTE

    Atingiu 100% de tempo - essa versão é melhor pelo 
    espaço O(1). De qualquer forma, o algoritmo abaixo 
    é contraintuitivo, mas é facilmente explicado. 
    
    Se temos floor(n/3), o valor máximo de candidatos será
    no máximo 2. Repare: se fixarmos um n = 10, temos que 
    floor(10/3) = 3. Logo, o limite mínimo é 3, o que faz
    com que selecionaremos apenas os que tem 4 ou mais. Mas, 
    se tivermos 3 candidatos com 4, teremos 12 números.
    Logo, isso é impossível, pois n = 10. Assim, podemos 
    ter no máximo 2 números.

    Se fosse floor(40/3), teríamos o limite de 13. Candidatos
    teriam que ter 14 ou mais. Voltamos ao mesmo problema,
    pois 2 teriam 28 (OK!), mas 3 teriam 42 (ERRO!).

    Assim, existe uma propriedade que fala que se um dos
    números aparece mais de floor(n/3), ele jamais será 
    cancelado com frequencia(x) == 0. Mas, ao final, ele
    pode ter uma contagem inferior ao floor(n/3). 

    Por isso, é necessário conferir se o valor realmente
    fará parte do resultado final.

*/ 
vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0;
    // diferentes para evitar colisão inicial
    int candidate1 = 0, candidate2 = 1; 

    // Fase 1: Encontrar candidatos
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Fase 2: Verificar candidatos
    count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    vector<int> res;
    int n = nums.size();
    if (count1 > n / 3) res.push_back(candidate1);
    if (count2 > n / 3) res.push_back(candidate2);
    return res;
}

int main(){

    vector<int> v = {1000000000};

    auto it = majorityElement(v);

    for(auto i : it) cout << i << ' ';

    return 0;
}