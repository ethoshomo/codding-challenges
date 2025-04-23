#include <iostream>
#include <stack>

using namespace std;

class MinStack_Lenta {
    stack<int> s;
    stack<int> min;
public:
    MinStack_Lenta() {}
    
    void push(int val) {
        s.push(val);
        if(min.top() <= val) min.push(val);
    }
    
    void pop() {
        if(!s.empty() && s.top() == min.top())
            min.pop();

        if(!s.empty()) 
            s.pop();
    }
    
    int top() {
        if(!s.empty())
            return s.top();
    }
    
    int getMin() {
        if(!s.empty())
            return min.top();
    }
};


class MinStack {
    stack<pair<int, int>> stack;
public:
    MinStack() {}
    
    void push(int val) {
        if (stack.empty()) {
            cout << val << endl;
            stack.push({val, val});
            return;
        }
        int curMin = stack.top().second;
        stack.push({val, min(curMin, val)});
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
    }
};

int main(){

    return 0;
}