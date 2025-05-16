/* 409. Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 
Constraints:
1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/
#include <iostream>
#include <vector>

using namespace std;

int longestPalindrome(string s) {
    int n = s.size();
    vector<int> count(128, 0); 

    for (char c : s)
        count[c]++;

    int total = 0;
    bool hasOdd = false;
    for (int freq : count) {
        total += (freq / 2) * 2; 
        if (freq % 2 == 1)
            hasOdd = true;
    }

    return hasOdd ? total + 1 : total;
}

int main(){

    string s = "abccccdd";

    cout << longestPalindrome(s);

    return 0;
}