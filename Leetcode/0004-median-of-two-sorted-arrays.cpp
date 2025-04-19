/* 
4. Median of Two Sorted Arrays
Hard
Topics
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
   
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());

    int median_index = nums1.size()/2;

    cout << (nums1.size() & 1 ? (double)nums1[median_index] : (double)(nums1[median_index-1]+nums1[median_index])/2);

    return 0;
}