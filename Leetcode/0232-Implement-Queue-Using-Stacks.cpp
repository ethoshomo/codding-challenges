/* 232. Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/
#include <iostream>
#include <deque>
#include <stack>

using namespace std;

// Jeito correto de implementar fila
class MyQueue_ {
    deque<int> d;
public:
    MyQueue_() {}
    void push(int x) {d.push_back(x);}
    int pop() {
        if(!d.empty()){
            int res = d.front();
            d.pop_front();
            return res;
        }
        return -1;
    }
    int peek() {
        if(!d.empty())
            return d.front();
        return -1;
    }
    bool empty() {return d.empty();}
};

// Forma pedida no exercício
class MyQueue {
    stack<int> st;
    stack<int> t;

public:
    MyQueue() {
    }
    
    void push(int x) {
        while(!st.empty()){
            t.push(st.top());
            st.pop();
        }
        t.push(x);
        while(!t.empty()){
            st.push(t.top());
            t.pop();
        }
    }
    
    int pop() {
        if(!st.empty()){
            int res = st.top();
            st.pop();
            return res;
        }
        return -1;
    }
    
    int peek() {
        if(!st.empty())
            return st.top();
        return -1;
    }
    
    bool empty() {
        return st.empty();
    }
};


int main(){

    auto st = MyQueue();
    st.push(1);
    st.push(2);
    cout << st.peek();
    cout << st.pop();
    cout << st.empty();

    return 0;
}