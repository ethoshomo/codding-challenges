/* 434. Number of Segments in a String

Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.

Example 1:
Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

Example 2:
Input: s = "Hello"
Output: 1
 
Constraints:
0 <= s.length <= 300
s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.
*/
#include <iostream>
#include <stack>

using namespace std;

int countSegments(string s) {
    // Limpa à direita
    while(!s.empty() && s[s.size()-1] == ' ')
        s.pop_back();

    // Verifica se a string está vazia
    if(s.size() == 0) return 0;

    stack<char> st;
    int i = 0, total = 1, sz = s.size();

    // Limpa à esquerda
    while(i < sz && s[i] == ' ') 
        i++;

    // Empilha eliminando mais de um espaço
    for(; i < s.size(); i++){
        if(!st.empty() && st.top() == ' ' && s[i] == ' '){
            // Nada
        }
        else
            st.push(s[i]);
    }

    // contabiliza os segmentos
    while(!st.empty()){
        if(st.top() == ' ') 
            total += 1;
        st.pop();
    }

    return total;
}

int main(){

    string s = "Hello, my name is John";
    cout << countSegments(s);
    return 0;
}