/*219- Contains Duplicate II
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;

bool containsNearbyDuplicate_slow(vector<int>& nums, int k) {
    
    int n = nums.size();
    if(n == 0) return false;

    for(int i = 0; i <= n; i++){
        int j = i+k;
        while(i != j){
            if(j < n && nums[i] == nums[j]) 
                return true;
            j--;
        }
    }

    return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map<int, int> m;
    int i, n = nums.size();

    for(i = 0; i < n; i++){
        if(m.find(nums[i]) != m.end() && abs(i - m[nums[i]]) <= k) return true;
        m[nums[i]] = i;
    }

    return false;
}


int main(){

    //vector<int> v = {1,2,3,1};
    //int k = 3;

    //vector<int> v = {1,0,1,1};
    //int k = 1;

    //vector<int> v = {1,2,3,1,2,3};
    //int k = 2;

    //vector<int> v = {1};
    //int k = 1;

    vector<int> v = {99,99};
    int k = 2;

    cout << containsNearbyDuplicate(v, k);

    return 0;
}