/*
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.
 

Example 1:


Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds
Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5

*/
#include <iostream>
#include <vector>

using namespace std;

int minTimeToVisitAllPointsSlow(vector<vector<int>>& points) {
        
    int total = 0;   
    int actualA, actualB, nextA, nextB;
    for(size_t i = 0; i < points.size()-1; i++){
        
        actualA = points[i][0];
        actualB = points[i][1];
        nextA = points[i+1][0]; 
        nextB = points[i+1][1];

        while(true){
            if(actualA != nextA || actualB != nextB){
                if (actualA < nextA)
                    actualA++;
                else if(actualA > nextA)
                    actualA--;

                if (actualB < nextB)
                    actualB++;
                else if(actualB > nextB)
                    actualB--;

                total+=1;
            }
            else 
                break;
        }
    }
    return total;
}

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    // Já está onde precisa visitar
    if(n <= 1) return 0;

    int time = 0, x, y;
    for(int i = 0; i < n-1; i++){
        //Distância atual para o próximo:
        x = abs(points[i+1][0]-points[i][0]);
        y = abs(points[i+1][1]-points[i][1]);
        time += min(x, y) + abs(x-y);
    }

    return time;
}

int main(){

    vector<vector<int>> v = {{1,1}, {3,4}, {-1,0}};

    cout << minTimeToVisitAllPoints(v);

    return 0;
}