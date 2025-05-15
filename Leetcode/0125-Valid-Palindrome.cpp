/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
#include <iostream>
#include <string>
#include <regex>

using namespace std;

// Versão lenta - mas, funciona.
bool isPalindrome_(string s) {
    
    regex pattern("[^A-Za-z0-9]+");
    string candidate = regex_replace(s, pattern,"");
    
    for(auto &c : candidate) 
        c = tolower(c);

    int l = 0, r = candidate.size()-1;
    while(l <= r){
        if (candidate[l] != candidate[r]) 
            return false;
        l++;
        r--;
    }

    return true;
}

// Versão otimizada
bool isPalindrome(string s) {
    
    int l = 0, r = s.size()-1;
    while(l < r){

        // Desconsidera caracteres não-alfanumericos
        while(l < r && !isalnum(s[l])) 
            l++;
        while(l < r && !isalnum(s[r])) 
            r--;
        
        // Compara caracteres
        if (tolower(s[l]) != tolower(s[r])) 
            return false;

        // Ajusta indexes
        l++;
        r--;
    }

    return true;
}

int main(){

    string s = "A man, a plan, a canal: Panama";

    cout << (isPalindrome(s) ? "TRUE" : "FALSE");
    return 0;
}