#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

/* PERMUTAÇÕES

O algoritmo gera embaralhamento do números em razão das sucessivas recursões
que são auxiliadas por dois ponteiros l (à esquerda) e r (à direita) sobre o
espaço vetorial de nums.

O algoritmo é composto de três passos essenciais: swap, recursão e swap. Isto
é, a cada iteração, o vetor l será deslocado uma unidade em direção ao final,
mas esse movimento será desfeito depois da recursão.

Dentro da recursão, um novo loop é realizado com o nums permutado, porém 
com l começando em uma unidade avançada. Isso vai gerar novas permutações 
e novas recursões. O processo se repete até que l=r, quando o algoritmo 
armazena a permutação e retrocede.

É sempre interessante lembrar que nums será retornado à configuração
inicial com o desfazimento do swap em todas as recursões. Isso permite 
um novo começo para uma nova combinação com l em outra posição. É um 
algoritmo bastante abstrato. 

*/
void helper(vector<int>& nums, int l, int r, vector<vector<int>>& result) {
    if (l == r) {
        result.push_back(nums);
        return;
    }

    for (int i = l; i <= r; ++i) {
        swap(nums[l], nums[i]);          // Gera variação
        helper(nums, l + 1, r, result);  // Recursão
        swap(nums[l], nums[i]);          // Desfaz a troca
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> r;
    helper(nums, 0, nums.size()-1, r);
    return r;
}

int main(){

    vector<int> v = {1,2,3};
    auto r = permute(v);
    
    for (auto c : r){
        for (auto d : c)
            cout << d << ' ';
        cout << '\n';
    }

    return 0;
}