#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Forma simples de resolução
class NumArray_easiest{
    vector<int> v;
public:
    NumArray_easiest(vector<int> &nums){
        v = nums;
    }

    int sumRange(int left, int right){
        right += 1;
        return accumulate(v.begin()+left, v.begin()+right, 0);
    }
};

// Utiliza soma prefixada para realizar cálculos.
// a técnica é indicada em razão da diretriz:
// At most 10^4 calls will be made to sumRange
class NumArray{
    vector<int> prefixada;
public:
    NumArray(vector<int> &nums){
        int n = nums.size();
        prefixada.resize(n+1, 0);
        for(int i = 0; i < n; i++) 
            prefixada[i+1] = prefixada[i] + nums[i];
    }

    int sumRange(int left, int right){
        return prefixada[right+1] - prefixada[left];
    }
};


int main(){
    return 0;
}