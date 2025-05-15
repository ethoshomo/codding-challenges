/* 394. Decode String

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string> 
#include <regex>

using namespace std;

// Com REGEX
string decodeString(string s) {

    // REGEX para Padrões como 2[c] (sem colchetes aninhados)
    regex pattern(R"((\d+)\[([^\[\]]*)\])"); 
    smatch match;
    
    // Variáveis de apoio
    int repeat = 0;
    string replacement = "";

    while (regex_search(s, match, pattern)) {
        // Coleta valor de repetição
        repeat = stoi(match[1]);
        
        // Constrói repetição
        replacement = "";
        for (int i = 0; i < repeat; ++i)
            replacement += match[2];
        
        // Substitui na string
        s.replace(match.position(0), match.length(0), replacement);
    }

    // Retorna string modificada
    return s;
}

string decodeString(string s) {
    stack<string> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ']')
            st.push(string(1,s[i]));
        else{

            // Recupera conteúdo de repetição
            string substr="";
            while(st.top() != "["){
                substr = st.top() + substr;
                st.pop();
            }
            // Pop "[""
            st.pop();

            // Coleta um ou mais digitos
            string k = "";
            while(!st.empty() && isdigit(st.top()[0])){
                k = st.top() + k;
                st.pop();
            }

            // Verifica se k é vazio.
            int num = k.empty() ? 0 : stoi(k);

            // Adiciona repetição na stack
            for(int i = 0; i < num; i++){
                st.push(substr);
            }
        }
    }

    // Monta resposta final com elementos
    // da stack
    string ans="";
    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }
    
    return ans;
}


int main(){

    string s = "2[abc]3[cd]ef";

    cout << decodeString(s);

    return 0;
}