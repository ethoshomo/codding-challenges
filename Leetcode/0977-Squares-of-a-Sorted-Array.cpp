/* 977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//Embora pareça rápido, existe um overhead alto
vector<int> sortedSquares_overhead(vector<int> &nums){
    int n = nums.size();
    multiset<int> m;

    for (int i = 0; i < n; i++)
        m.insert(nums[i] * nums[i]);

    return vector<int>(m.begin(), m.end());
}

// Em termos de equilibrio, é o melhor código
vector<int> sortedSquares_easiest(vector<int> &nums){
    int n = nums.size();

    for (int i = 0; i < n; i++)
        nums[i] = nums[i] * nums[i];

    sort(nums.begin(), nums.end());

    return nums;
}

/*
Mais rápida, mas nem tanto... a complicação não vale o código

A lógica é comparar os absolutos dos extremos e levar
os ponteiros para o mesmo elemento no mesmo da lista em
direção ao zero. O processo iterativo termina quando o
ponteiro da esquerda ficar maior que o ponteiro da direita.
Se forem iguais, é porque estão sobre o mesmo e último
elemento da lista que precisa ser operado. 
*/ 
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1, pos = n - 1;

    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[pos--] = nums[left] * nums[left];
            left++;
        } else {
            result[pos--] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}

int main(){

    vector<int> v = {-7,-3,2,3,11};

    vector<int> r = sortedSquares(v);

    for (auto c : r)
        cout << c << ' ';

    return 0;
}