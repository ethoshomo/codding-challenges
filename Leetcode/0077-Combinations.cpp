/* 77. Combinations

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 
Constraints:

1 <= n <= 20
1 <= k <= n
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////
void helper_recursive_slow(vector<int> nums, int k, vector<int> s, vector<vector<int>>& r){
    
    if (k == 0){
        sort(s.begin(), s.end());
        if(find(r.begin(), r.end(), s) == r.end())
            r.push_back(s);
        return;
    }

    for (auto n : nums){
        if (find(s.begin(), s.end(), n) == s.end())
        {
            s.push_back(n);
            helper_recursive_slow(nums, k - 1, s, r);
            s.pop_back();
        }
    }
}

vector<vector<int>> combine_recursive_slow(int n, int k){
    vector<vector<int>> r;
    vector<int> nums;

    for (int i = 1; i <= n; i++)
        nums.push_back(i);


    for (int i = 1; i <= n; i++){
        vector<int> solution;
        solution.push_back(i);
        helper_recursive_slow(nums, k - 1, solution, r);
        solution.pop_back();
    }

    return r;
}

////////////////////////////////////////////////////////////////////////////////////
/*
    A versão de recursão mais otimizada funciona porque
    o array inicial de elementos é produzido de forma 
    sequencialmente ordenada e não possui elementos que 
    se repetem. Isso possibilita o uso de um start na 
    recursão para gerar combinações a partir de um dado
    número. Isso simplifica muito o código. Se os
    elementos repetissem ou não tivessemos uma lista 
    ordenada, o caso era fazer a ordenação e o find.
*/
void helper(int start, int n, int k, vector<int>& s, vector<vector<int>>& r) {
    if (k == 0) {
        r.push_back(s);
        return;
    }

    for (int i = start; i <= n; ++i) {
        s.push_back(i);
        helper(i + 1, n, k - 1, s, r);
        s.pop_back();
    }
}

vector<vector<int>> combine_recursive_fast(int n, int k) {
    vector<vector<int>> r;
    vector<int> s;
    helper(1, n, k, s, r);
    return r;
}


////////////////////////////////////////////////////////////////////////////////////
/* 
    A programação dinâmica melhora, mas não muito. 
*/
vector<vector<int>> combine_iterative(int n, int k) {
    vector<vector<int>> res;
    vector<int> comb(k, 0);
    int i = 0;

    while (i >= 0) {
        comb[i]++;

        if (comb[i] > n) {
            i--; // backtrack
        } else if (i == k - 1) {
            res.push_back(comb); // combinação completa
        } else {
            i++;
            comb[i] = comb[i - 1]; // começa do valor anterior
        }
    }

    return res;
}

/* 
    VERSÃO MAIS OTIMIZADA 
    É a versão mais otimizada, mas é complexa. 
    Em situações de pressão, compensa usar a recursiva. 
*/
vector<vector<int>> combine(int n, int k) {
    
    vector<vector<int>> res;

    // 1ª Otimização: reserva de memória do total de 
    // combinações. Estimativa de combinações: C(n, k).
    // Isso evita realocações.
    int combCount = 1;
    for (int i = 1; i <= k; ++i)
        combCount = combCount * (n - i + 1) / i;
    res.reserve(combCount); 

    // Vetor Temporário de Combinações
    // Poussui k posições zeradas: 
    // k=2 => [0,0]
    vector<int> comb(k, 0); 
    
    // i: posição de modificação
    int i = 0;
    while (i >= 0) {
        // Aumenta em 1 a posição atual
        comb[i]++;

        // Poda: se não há elementos suficientes restantes => backtraking
        if (comb[i] > n - (k - 1 - i)) {
            i--; 
        } else if (i == k - 1) {
            // combinação completa. emplace é mais rápido que push_back
            res.emplace_back(comb); 
        } else {
            // As combinações são progressivas, nunca repetindo o valor 
            // utilizado anteriormente. Por isso, elas começam no novo
            // index a partir do valor anterior.
            i++;
            comb[i] = comb[i - 1]; 
        }
    }

    return res;
}


int main(){

    vector<vector<int>> r = combine(4, 2);

    for (auto c : r)
    {
        for (auto d : c)
            cout << d << ' ';
        cout << '\n';
    }

    return 0;
}