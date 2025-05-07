/* 120. Triangle

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10

Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 
Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int u = triangle.size();
    int v = triangle.back().size();

    vector<vector<int>> dp (u+1, vector<int>(v+1, 100000));
    dp[1][1] = triangle[0][0];

    for(int i = 2; i <= u; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i-1][j-1];

    return *min_element(dp[u].begin(), dp[u].end());
}

int main(){
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };

    cout << minimumTotal(triangle);

    return 0;
}