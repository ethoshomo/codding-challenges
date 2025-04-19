/* 209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits.h>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    int l = 0, total = 0, minLength = INT_MAX;

    for (int r = 0; r < n; ++r) {
        total += nums[r];

        while (total >= target) {
            minLength = min(minLength, r - l + 1);
            total -= nums[l++];
        }
    }
    return (minLength == INT_MAX) ? 0 : minLength;
}


int main(){

    //int target = 7;
    //vector<int> v = {2,3,1,2,4,3};

    // int target = 11;
    // vector<int> v = {1,1,1,1,1,1,1,1};

    int target = 213;
    vector<int> v = {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};

    cout << minSubArrayLen(target, v);

    return 0;
}