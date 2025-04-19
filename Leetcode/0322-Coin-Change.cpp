/*322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 
Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;



int coinChange(vector<int>& coins, int amount) {
    
    int n = amount+1;
    vector<int> dp(n, amount+1);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(auto c: coins){
            if(i-c >= 0)
                dp[i] = min(dp[i], dp[i-c]+1);
        }
    } 

    return dp[amount] != amount+1 ? dp[amount] : -1;

}

int main(){

    //vector<int> coins = {1,2,5};
    //int amount = 11;
    
    vector<int> coins = {2};
    int amount = 3;
    
    //vector<int> coins = {1};
    //int amount = 0;
    
    cout << coinChange(coins, amount);
    
    return 0;
}