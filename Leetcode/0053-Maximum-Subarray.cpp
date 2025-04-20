/* 53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits.h>

using namespace std;

int maxSubArray_slower(vector<int>& nums) {
    int maxSum = INT_MIN;
    int n = nums.size();

    for(int window = 0; window < n; window++){
        for(int start = 0; start+window < n; start++){
            auto b = nums.begin()+start;
            auto e = nums.begin()+start+window;
            int sum = accumulate(b, e, 0);
            if (sum > maxSum) maxSum = sum;
        }

    }    
    return maxSum;
}


/*      Algoritmo de Kadane
    O algoritmo é muito simples, pois temos apenas uma escolha 
    para fazer: ou a gente começa a contagem no valor atual (nums[i]),
    ou a gente aproveita a contagem corrente (current_sum + nums[i]).
    Depois, se for o caso, atualizamos o maxSum.

    De certa forma, isso é programação dinâmica, pois, em todos os estados,
    a gente decide se vai começar uma nova contagem ou se vai persistir na
    contagem anterior. Isto é, trabalhamos com a solução ótima em todos os
    estágios. Por exemplo: {-2,1,-3,4,-1,2,1,-5,4}

        comeca             continua
        denovo            somatório
    max(<atual>, <somatorio:acumulado+atual>)
    
    Iniciamos com -2.
    max(1, -2+1 = -1) = 1
    max(-3, 1-3 = -2) = -2
    max(4, -2+4 = 2) = 4
    max(-1, 4-1 = 3) = 3
    max(2, 3+2 = 5) = 5
    max(1, 5+1 = 6) = 6  <- Soma máxima atingida
    max(-5, 6-5 = 1) = 1
    max(4, 1+4 = 5) = 5

    Se quiser coletar os indices, precisa fazer os ifs.
*/
int maxSubArray(vector<int>& nums) {
    int current_sum = nums[0];
    int max_sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main(){

    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(v);

    return 0;
}