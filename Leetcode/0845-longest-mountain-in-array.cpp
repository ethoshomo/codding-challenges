/*  845. Longest Mountain in Array

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
 
Follow up:

Can you solve it using only one pass?
Can you solve it in O(1) space?
*/

#include <iostream>
#include <vector>

using namespace std;


int longestMountain(vector<int>& arr) {

    int n = arr.size();
    if(n < 3) return 0;

    int longest = 0;
    for(int i = 1; i < n-1; i++){
        if(arr[i] > arr[i-1] && arr[i+1] < arr[i]){
            
            int l = i-1;
            int r = i+1;

            while(l >= 0 && arr[l] < arr[l+1]) l--;
            while(r < n && arr[r] < arr[r-1]) r++;
            
            longest = max(longest, r-l-1);
        }
    }

    return longest;
}

int main(){

    //vector<int> v = {2,1,4,7,3,2,5};
    //vector<int> v = {0,1,2,3,4,5,4,3,2,1,0};
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
 
    cout << longestMountain(v);

    return 0;
}