/* 645. Set Mismatch

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]
 
Constraints:
2 <= nums.length <= 104
1 <= nums[i] <= 104
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    
    vector<int> res;
    unordered_map<int, int> map;

    int n = nums.size(), missing = 0;
    for(int i = 0; i < n; i++){
        if(map[nums[i]]){
            res.push_back(nums[i]);
        }
        else{
            map[nums[i]] = 1;
            missing ^= nums[i];
        }
    }

    for(int i = 1; i <= n; i++)
        missing ^= i;

    res.push_back(missing);

    return res;
}

int main(){

    vector<int> nums = {1,2,2,4};

    auto it = findErrorNums(nums);

    for(auto &i : it) cout << i << ' ';

    return 0;
}