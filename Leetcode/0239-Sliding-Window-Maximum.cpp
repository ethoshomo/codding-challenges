/* 239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

 Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/
#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

// SOLUÇÃO LENTA O(nlogn)
vector<int> maxSlidingWindow_(vector<int> &nums, int k){
    if (nums.empty() || k == 0)
        return {};
    if (k == 1)
        return nums;

    vector<int> r;
    multiset<int> m;
    int n = nums.size();

    for (int i = 0; i < n; i++){
        m.insert(nums[i]);

        if (i >= k - 1){
            r.push_back(*m.rbegin());
            m.erase(m.find(nums[i - k + 1]));
        }
    }

    return r;
}

// Solução rápida O(n)
vector<int> maxSlidingWindow(vector<int> &nums, int k){
    int n = nums.size(), idx = 0;
    vector<int> r(n - k + 1);
    deque<int> d;

    for (int i = 0; i < n; i++){
        // Remover índices fora da janela
        if (!d.empty() && d.front() <= i - k)
            d.pop_front();

        // Remover do fundo os índices de elementos menores
        while (!d.empty() && nums[d.back()] < nums[i])
            d.pop_back();

        d.push_back(i);

        // Começar a preencher resultado quando a janela estiver cheia
        if (i >= k - 1)
            r[idx++] = nums[d.front()];
    }

    return r;
}

int main(){
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    auto it = maxSlidingWindow(v, k);

    for (auto i : it)
        cout << i << ' ';

    return 0;
}