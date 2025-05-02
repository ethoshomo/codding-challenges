/* 56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

// VERSÃO LENTA
vector<vector<int>> merge_(vector<vector<int>>& intervals) {
    if(intervals.size() <= 1) return intervals;
   
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    });

    deque<vector<int>> q(intervals.begin(), intervals.end());
    vector<vector<int>> r;

    bool adding = false;
    while(!q.empty()){
        
        vector<int> ref = q.front();
        q.pop_front();

        adding = true;
        for(int j = 0; j < static_cast<int>(r.size()); j++){
            if(!(ref[1] < r[j][0] || ref[0] > r[j][1])){
                //cout << "R(" << r[j][0] <<','<< r[j][1] << ")  REF(" << ref[0] << ',' << ref[1] << ")\n"; 
                adding = false;
                r[j][0] = min(r[j][0], ref[0]);
                r[j][1] = max(r[j][1], ref[1]);
            }
        }
        if(adding) r.push_back(ref);
    }
    return r;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

int main(){

    vector<vector<int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    auto it = merge(intervals);

    for(auto i : it){
        for(auto e: i){
            cout << e << ' ';
        }
        cout << '\n';
    }

    return 0;
}