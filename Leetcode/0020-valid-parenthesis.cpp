/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <stack>

using namespace std;

bool valid(string s){
    if(s.empty()) return false;
    stack<char> stk;

    stk.push(s[0]);
    for(size_t i = 1; i < s.size(); i++){

        if ((s[i] == ')' && !stk.empty() && stk.top() == '(') || 
            (s[i] == ']' && !stk.empty() && stk.top() == '[') || 
            (s[i] == '}' && !stk.empty() && stk.top() == '{') )
            stk.pop();
        else if( s[i] == ')' || s[i] == ']' || s[i] == '}')
            return false;
        else
            stk.push(s[i]);
    }
    
    if(stk.empty()) 
        return true;
    return false;
}

int main(){
    string s = "(){}}{";
    //string s = "()[]{}";
    //string s = "([])";
    //string s = "()";
    //string s = "(]";
    
    cout << valid(s);

    return 0;
}