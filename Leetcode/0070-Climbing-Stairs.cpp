/* 70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45

*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int climbing(int n, vector<int> &dp){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != INT_MAX) return dp[n];
    dp[n] = climbing(n-1, dp) + climbing(n-2, dp);
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp(n+1, INT_MAX);
    return climbing(n,dp);
}

int main(){

    int n = 3;
    cout << climbStairs(n);
    return 0;
}
