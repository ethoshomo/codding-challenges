/*
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    
    unordered_map<char,char> map;
    unordered_map<char,char> pam;
    char c1, c2;

    for(int i = 0; i < s.length(); i++){
        c1 = s[i];
        c2 = t[i];
        
        if(map.count(c1)){
            if(map[c1] != c2) 
                return false;
        }
        else{
            map[c1] = c2;
        }

        if(pam.count(c2)){
            if(pam[c2] != c1)
                return false;
        }
        else{
            pam[c2] = c1;
        }
    }
    
    return true;
}

int main(){

    string  s = "foo", t = "bar";
    cout << (isIsomorphic(s,t) ? "TRUE" : "FALSE");

    return 0;
}