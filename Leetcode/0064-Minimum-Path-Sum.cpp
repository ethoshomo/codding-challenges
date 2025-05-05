/*64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Versão recursiva - lenta
int helper(int m, int n, vector<vector<int>>& g, vector<vector<int>>& dp){
    int line = g.size(), col = g[0].size();
    if(m < 0 || n < 0 || m >= line || n >= col) return numeric_limits<int>::max();
    if(m == line-1 && n == col-1) return dp[m][n] = g[m][n];
    if(dp[m][n] != -1) return dp[m][n];
    return dp[m][n] = min(helper(m+1, n, g, dp), helper(m, n+1, g, dp))+g[m][n];
}

int minPathSum_(vector<vector<int>>& grid) {
    int lin = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(lin, vector<int>(col, -1));  
    return helper(0, 0, grid, dp);
}

// Versão iterativa - Beats 100%
int minPathSum(vector<vector<int>>& grid) {
    
    int lin = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(lin, vector<int>(col, 0));

    for(int j = 0; j < col; j++)
        dp[0][j] = grid[0][j] + (j-1 >= 0 ? dp[0][j-1]: 0);
    
    for(int i = 0; i < lin; i++)
        dp[i][0] = grid[i][0]+ (i-1 >=0 ? dp[i-1][0]: 0);

    for(int i = 1; i < lin; i++)
        for(int j = 1; j < col; j++)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1])+grid[i][j];

    return dp[lin-1][col-1];
}

int main(){

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    cout << minPathSum_(grid);

    return 0;
}