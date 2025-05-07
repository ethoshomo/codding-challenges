/* 119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
 
Constraints:
0 <= rowIndex <= 33

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/
#include <iostream>
#include <vector>

using namespace std;

int combinatory(int n, int k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k;

    unsigned long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return (int)res;
}

vector<int> getRow(int rowIndex) {

    vector<int> r;
    for(int i = 0; i <= rowIndex; i++)
        r.push_back(combinatory(rowIndex, i));

    return r;
}

int main(){
    int n = 21;
    auto it = getRow(n);
    for(auto i: it) cout << i << ' ';
    return 0;
}