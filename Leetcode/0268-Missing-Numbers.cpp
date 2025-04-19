/* MISSING NUMBERS
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]

Output: 2

Explanation:

n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]

Output: 8

Explanation:

n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 
Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int missingNumber_fastest(vector<int> &nums){

    int n = nums.size();
    int res = 0;

    // res vira o xor de todos os números esperados
    // 0, 1, .., n
    for (int i = 0; i <= n; i++)
        res ^= i;

    // res faz o xor de todos os valores que existem
    // a^a = 0 | a^0 = a | a^b^a = b (sobra o que não tem)
    for (size_t i = 0; i < nums.size(); i++)
        res ^= nums[i];

    return res;
};

// Usando soma gaussiana (capaz que foi mais rápido que a acima... rs)
int missingNumber(vector<int>& nums) {

    int total = 0;
    for(auto c: nums) total += c;
    
    return (nums.size()*(nums.size()+1))/2 - total;
}

int missingNumber_1(vector<int>& nums) {
    
    int n = nums.size();

    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < n; i++){
        if(nums[i] != i){
            return i;
        }
    }
    return nums.size();
}

int main()
{

    vector<int> v = {9,6,4,2,3,5,7,0,1};

    cout << missingNumber(v);

    return 0;
}