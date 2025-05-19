/* 905. Sort Array By Parity

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Example 2:
Input: nums = [0]
Output: [0]
 
Constraints:
1 <= nums.length <= 5000
0 <= nums[i] <= 5000
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
        if (nums[l] % 2 == 0)
            l++;
        else if (nums[r] % 2 == 1)
            r--;
        else {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    return nums;
}



int main(){

    vector<int> nums = {1};
    
    auto it = sortArrayByParity(nums);

    for(auto i: it) cout << i << ' ';

    return 0;
}