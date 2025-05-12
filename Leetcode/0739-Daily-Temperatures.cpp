#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> s; // Armazena indices

    for(int i = 0; i < n; i++) {
        while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    return answer;
}


int main(){

    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    auto it = dailyTemperatures(temperatures);

    for(auto& i: it) cout << i << ' ';

    return 0;
}