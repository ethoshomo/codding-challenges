/* 290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:
'a' maps to "dog".
'b' maps to "cat".

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false


Constraints:
1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s) {
    
    unordered_map<char, string> map;
    unordered_map<string, char> pam;

    int l = 0, r = 0;

    for (int i = 0; i < pattern.length(); i++) {
        while (r < s.size() && s[r] != ' ') 
            r++;
        
        if (l >= s.size()) 
            return false;

        string b = s.substr(l, r - l);
        char a = pattern[i];

        if (map.count(a)) {
            if (map[a] != b)
                return false;
        } else
            map[a] = b;

        if (pam.count(b)) {
            if (pam[b] != a)
                return false;
        } else 
            pam[b] = a;

        r++;
        l = r;
    }

    // Verifica se há palavras restantes em s
    if (r < s.size()) 
        return false;

    return true;
}


int main(){

    string pattern = "abba", s = "dog cat cat dog";
    cout << wordPattern(pattern, s);

    return 0;
}