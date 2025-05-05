/* 91. Decode Ways

You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: s = "12"
Output: 2
Explanation:
"12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "226"
Output: 3
Explanation:
"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:
Input: s = "06"
Output: 0
Explanation:
"06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.

Constraints:
1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/
#include <iostream>
#include <vector>

using namespace std;

// Versão recursiva
int recursion(string s, int i, vector<int>& dp){
    int n = s.size();
    if(i == n) return 1;
    if(s[i] == '0') return 0;
    if(dp[i] != -1) return dp[i];

    int total = recursion(s, i+1, dp);
    
    if(i+1 < n){
        int two = stoi(s.substr(i,2));
        if(two >= 10 && two <= 26) total += recursion(s, i+2, dp);
    }

    return dp[i] = total;
}
int numDecodings(string s) {
    vector<int> dp(s.size()+1, 0);
    return recursion(s, 0, dp);
}

// Versão iterativa - mais otimizada
int numDecodings(string s) {
    // String size
    int n = s.size();

    // Exceptions
    if(n == 0 || s[0] == '0') return 0;

    // Memoization
    vector<int> dp(n+1, -1);

    // Base
    dp[0] = 1; // empty string ""
    dp[1] = 1; // first valid letter

    for(int i = 2; i <= n; ++i){
        if(s[i-1] != '0') 
            dp[i] += dp[i-1];

        int two = stoi(s.substr(i-2,2));
        if(two >= 10 && two <= 26) 
            dp[i] += dp[i-2];
    }

    return dp[n];
}

int main(){

    string s = "226";

    cout << numDecodings(s);

    return 0;
}