/*844. Backspace String Compare

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 
Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.

Follow up: Can you solve it in O(n) time and O(1) space?
*/
#include <iostream>
#include <stack>

using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> s1;
    stack<char> s2;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            if(!s1.empty()) 
                s1.pop();
        }
        else{
            s1.push(s[i]);
        }
    }

    for(int i = 0; i < t.size(); i++){
        if(t[i] == '#'){
            if(!s2.empty()) 
                s2.pop();
        }
        else{
            s2.push(t[i]);
        }
    }

    while(!s1.empty() && !s2.empty()){
        if(s1.top() != s2.top()) return false;
        s1.pop();
        s2.pop();
    }

    return s1.empty() == s2.empty();
}

int main(){
    // TRUE
    //string s1 = "ab##";
    //string s2 = "c#d#";

    string s1 = "a#c";
    string s2 = "b";

    cout << (backspaceCompare(s1, s2) ? "TRUE" : "FALSE");

    return 0;
}