/* 628. Maximum Product of Three Numbers

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6


Constraints:
3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(nlogn)
int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return max({ 
        nums[0]*nums[n-1]*nums[n-2],
        nums[0]*nums[1]*nums[n-1],
        nums[0]*nums[1]*nums[2],
        nums[n-3]*nums[n-2]*nums[n-1]
    });
}

int main(){

    vector<int> v = {1,2,3,4};
    cout << maximumProduct(v);

    return 0;
}