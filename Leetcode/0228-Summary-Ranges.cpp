/* 228. Summary Ranges

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
 
Constraints:
0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    
    vector<string> r = {};
    int a=0, b=0, n=nums.size();
    
    if(n == 0) 
        return r;
    else if(n == 1) {
        r.push_back(to_string(nums[0]));
        return r;
    }
    
    while(b < n){
        b++;
        if(b >= n || nums[b] != nums[b-1]+1){
            string str = "";
            if(a == b-1) 
                str = to_string(nums[a]);
            else{
                str = to_string(nums[a])+"->"+to_string(nums[b-1]);
            }
            r.push_back(str);
            a = b;
        }
    }
    return r;
}

int main(){

    vector<int> v = {0,2};

    auto it = summaryRanges(v);

    for(auto i: it) cout << i << ' ';

    return 0;
}