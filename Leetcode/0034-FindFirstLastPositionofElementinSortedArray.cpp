/* 34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target){
    vector<int> r(2, -1);

    if(nums.size() == 0) return r;

    auto it = lower_bound(nums.begin(), nums.end(), target);
    auto it2 = upper_bound(nums.begin(), nums.end(), target);

    if (it != nums.end() && *it == target)
        r[0] = it - nums.begin();
    else
        r[0] = -1;

    if (it2 != nums.begin() && *(it2 - 1) == target)
        r[1] = it2 - nums.begin() - 1;
    else
        r[1] = -1;

    return r;
}

int main(){

    vector<int> v = {};

    vector<int> r = searchRange(v, 6);

    cout << r[0] << ' ' << r[1];

    return 0;
}