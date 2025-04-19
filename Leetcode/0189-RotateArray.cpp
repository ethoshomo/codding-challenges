#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){

    vector<int> v = {1,2,3,4,5,6,7};
    vector<int> r(v.size(), 0);
    int k = 3;

    for(size_t i = 0; i < v.size(); i++)
        r[(i+k)%v.size()] = v[i];

    cout<< '\n';
    for (auto c: r) cout << c << ' ';

    return 0;
}