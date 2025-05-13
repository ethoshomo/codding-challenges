/* 387. First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0
Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:
1 <= s.length <= 105
s consists of only lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int firstUniqChar(string str) {
    int n = str.size();
    vector<int> count(26, 0);

    for(auto s : str) 
        count[s-'a']++;

    for(int i = 0; i < n; i++) 
        if(count[str[i]-'a'] == 1) 
            return i;
    
    return -1;
}

int main(){

    //string s = "leetcode";
    string s = "aabb";

    cout << firstUniqChar(s);

    return 0;
}