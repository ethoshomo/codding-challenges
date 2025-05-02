/* 57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void print(vector<int> &r){
    for(auto e: r) cout << e << ' ';
    cout << endl;
}


vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int iSize = intervals.size();
    int iNewInterval = newInterval.size();

    if (!iNewInterval)
        return intervals;

    // Se intervals está vazio, apenas retorna newInterval
    if (!iSize) {
        intervals.push_back(newInterval);
        return intervals;
    }

    vector<vector<int>> r;
    deque<vector<int>> q(intervals.begin(), intervals.end());

    vector<int> aux;

    while (true) {
        aux = q.front();
        q.pop_front();

        if (newInterval[0] > aux[1]) {
            r.push_back(aux);
            if (q.empty()) {
                r.push_back(newInterval);
                return r;
            }
        } 
        else if (newInterval[1] < aux[0]) {
            r.push_back(newInterval);
            r.push_back(aux);
            while (!q.empty()) {
                r.push_back(q.front());
                q.pop_front();
            }
            return r;
        } 
        else {
            // Início da fusão de intervalos sobrepostos
            r.push_back({
                min(newInterval[0], aux[0]),
                max(newInterval[1], aux[1]),
            });
            break;
        }
    }

    // Continua a fusão com outros intervalos sobrepostos
    while (!q.empty()) {
        aux = q.front();
        q.pop_front();

        if (r.back()[1] < aux[0]) {
            r.push_back(aux);
        } else {
            r.back()[0] = min(r.back()[0], aux[0]);
            r.back()[1] = max(r.back()[1], aux[1]);
        }
    }

    return r;
}

int main(){
    
    //vector<vector<int>> intervals = {
    //    {1,2},{3,5},{6,7},{8,10},{12,16}
    //};
    //vector<int> newInterval = {4,8};

    vector<vector<int>> intervals = {
        {1,5}
    };
    vector<int> newInterval = {0,0};
    auto it = insert(intervals, newInterval);

    for(auto i : it){
        for(auto e: i){
            cout << e << ' ';
        }
        cout << '\n';
    }

    return 0;
}