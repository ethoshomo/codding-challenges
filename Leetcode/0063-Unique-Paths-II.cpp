#include <iostream>
#include <vector>

using namespace std;

// Precisa ter memoização.
int helper(int m, int n, vector<vector<int>>& o, vector<vector<int>>& memo){
    if(m >= o.size() || n >=o[0].size() || o[m][n] == 1) return 0;
    if(m == 0 && n == 0) return 1;
    if(memo[m][n] != -1) return memo[m][n];
    return memo[m][n] = helper(m-1, n, o, memo) + helper(m, n-1, o, memo);
}

int uniquePathsWithObstacles_(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    return helper(m-1, n-1, obstacleGrid, memo);
}

// Programação Dinâmica - Melhor em tempo e espaço.
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    // Posição inicial
    dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

    // Primeira linha: se não tiver obstáculo, 1.
    // com obstáculo ou depois dele, 0
    for(int i = 1; i < n; i++)
        dp[0][i] = (obstacleGrid[0][i] == 0 && dp[0][i-1] == 1) ? 1 : 0;

    // Primeira coluna: se não tiver obstáculo, 1.
    // com obstáculo ou depois dele, 0.
    for(int i = 1; i < m; i++)
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;

    // Calcula o meio, que pode receber caminhos de cima
    // ou do lado esquerdo
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            if(obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    
    return dp[m-1][n-1];
}

int main(){
    vector<vector<int>> v = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout << uniquePathsWithObstacles(v);

    return 0;
}