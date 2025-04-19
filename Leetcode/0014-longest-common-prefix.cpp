/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    vector<string> strs = {"flower","flow","flight"};
    int tam = 10000000;

    for(size_t i = 1; i < strs.size(); i++){
        int tam_temp = 0;
        for(size_t j = 0; j < min(strs[i].size(), strs[i-1].size()); j++)
            if (strs[i][j] == strs[i-1][j])
                tam_temp += 1;
            else 
                break;
        
        if (tam_temp < tam)
            tam = tam_temp;
    }

    cout << strs[0].substr(0,tam);

    return 0;
}
