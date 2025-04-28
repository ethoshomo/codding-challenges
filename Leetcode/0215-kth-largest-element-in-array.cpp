/* 215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 
Constraints:
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int findKthLargest_(vector<int> &nums, int k){
    priority_queue<int, vector<int>> q(nums.begin(), nums.end());
    int c = 0, n = -100000;
    while (c < k){
        n = q.top();
        q.pop();
        c++;
    }
    return n;
}

int findKthLargest(vector<int> &nums, int k){
    sort(nums.begin(), nums.end());
    return nums[k-1];
}

int main(){

    vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << findKthLargest(v, 4);

    return 0;
}