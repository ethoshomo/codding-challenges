/*
58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

*/
#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int n = s.size();

    // Retirar espaços em branco no final
    for(int i = n-1; i >= 0; i--){
        if(s[i] == ' ') 
            s.pop_back();
        else
            break;
    }

    // Contar último caracter
    int ans = 0;
    n = s.size();
    for(int i = n-1; i >= 0; i--){
        if(s[i] != ' ')
            ans++;
        else 
            break;
    }

    return ans;
}

int main(){
    
    //string s = "   fly me   to   the moon  ";
    //string s = "Hello World";
    string s = "a";

    cout << lengthOfLastWord(s);

    return 0;
}