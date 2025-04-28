/* 347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    
    vector<int> r;  
    unordered_map<int, int> count;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        
    for(auto n : nums)
        count[n]++;
    
    for(auto c : count){
        heap.push({c.second, c.first});
        if(static_cast<int>(heap.size()) > k) heap.pop();
    }

    while(!heap.empty()){
        r.push_back(heap.top().second);
        heap.pop();
    }

    return r;
}

int main(){
    vector<int> v ={-1, -1};
    int k = 2;

    vector<int> r = topKFrequent(v, k);

    for(auto n : r) cout << n << ' ';
    return 0;
}