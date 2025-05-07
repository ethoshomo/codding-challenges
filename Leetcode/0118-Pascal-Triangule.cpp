/*118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
 
Constraints:
1 <= numRows <= 30
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v;
    
    v.push_back(vector<int>{1});
    for(int i = 1; i < numRows; i++){
        vector<int> line;
        line.push_back(1);
        for(int j = 1 ; j < i; j++)
            line.push_back(v[i-1][j]+v[i-1][j-1]);
        line.push_back(1);
        v.push_back(line);
    }

    return v;
}

int main(){

    int n = 5;

    auto it = generate(n);

    for(auto i:it){
        for(auto c:i) 
            cout << c << ' ';
        cout << '\n';
    }

    return 0;
}