/*136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int singleNumber_slower(vector<int>& nums) {
    
    int n = nums.size();       
    if(n == 1)  return nums[0];

    sort(nums.begin(), nums.end());

    if(nums[0] == nums[1]){
        for(int i = 1; i < n; i+= 2){
            if(nums[i-1] != nums[i]) 
                return nums[i-1];
        }
        return nums[n-1];
    }
    else{
        return nums[0];
    }
    return 0;
}

/* 
A ideia de usar o operador bitwise XOR consiste no fato de que
a ^ a = 0
a ^ 0 = a
Ou seja, como iniciamos com o valor 0, se temos dois valores 'a', 
eles serão anulados no set, exceto o que aparece uma única vez.
*/
int singleNumber(vector<int>& nums) {
    int number = 0;
    
    for(auto n : nums)
        number ^= n;
    
    return number;
}

int main (){

    //vector<int> v = {4,1,2,1,2};
    vector<int> v = {2,2,1};
    cout << singleNumber(v);

    return 0;
}