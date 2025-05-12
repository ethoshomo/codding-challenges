/* 224. Basic Calculator

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23


Constraints:
1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*/

#include <iostream>
#include <stack>

using namespace std;

int calculate(string s) {
    int number = 0;
    int res=0;
    int sign= 1;
    stack<int> st;

    for(char c: s){
        if(isdigit(c)){
            number = number*10+(c-'0');
        }
        if(c == '+'){
            res+= number*sign;
            number=0;
            sign=1;
        }
        if(c == '-'){
            res+= number*sign;
            number=0;
            sign=-1;
        }
        if(c == '('){
            st.push(res);
            st.push(sign);
            res=0;
            number=0;
            sign=1;
        }
        if(c == ')'){
            res+= number*sign;
            number=0;
            int stackSign = st.top(); st.pop();
            int stackVal = st.top(); st.pop();
            res*= stackSign;
            res+=stackVal;
        }
    }
    res+= number*sign;
    return res;
}

int main(){

    string s = "((10+1)+543)";

    cout << calculate(s);

    return 0;
}