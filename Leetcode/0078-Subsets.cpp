#include <iostream>
#include <vector>

using namespace std;

// Versão recursiva muito mais rápida nos testes
void helper(vector<int>& nums, vector<int>& p, int n, vector<vector<int>>& r){
    if(n == static_cast<int>(nums.size())) {
        if(p.empty()) 
            r.push_back({});
        else
            r.push_back(p);
        return;
    }

    p.push_back(nums[n]);
    helper(nums, p, n+1, r);
    p.pop_back();
    helper(nums, p, n+1, r);

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> r;
    vector<int> p;
    helper(nums, p, 0, r);
    return r;
}

// Versão iterativa: mais lenta
// A ideia aqui é iterar sobre os números de nums. 
// A cada rodada, criamos uma lista temporaria com os valores
// existentes anteriormente e, ao final, concatenamos as 
// respostas.
vector<vector<int>> subsets_int(vector<int>& nums) {
    vector<vector<int>> results;
    int n = nums.size();

    results.push_back({});
    for(int i = 0; i < n; i++){
        vector<vector<int>> tmp;
        for(auto r: results){
            vector<int> new_r(r.begin(), r.end());
            new_r.push_back(nums[i]);
            tmp.push_back(new_r);
        }
        results.insert(results.end(),tmp.begin(), tmp.end());
    }

    return results;
}

int main(){
    vector<int> v = {1,2,3};

    vector<vector<int>> r = subsets(v);
    
    for(auto r1: r){
        for(auto r2: r1)
            cout << r2 << ' ';
        cout << '\n';
    }
    return 0;
}