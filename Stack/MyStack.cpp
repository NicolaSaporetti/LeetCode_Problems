#include <iostream>
#include <deque>

using namespace std;

class MyStack {
private:
    deque<int> mydeque;
public:
    MyStack() {
    }
    
    void push(int x) {
        mydeque.push_front(x);
    }
    
    int pop() {
        int result = top();
        mydeque.pop_front();
        return result;
    }
    
    int top() {
        return mydeque.front();
    }
    
    bool empty() {
        return mydeque.empty();
    }
};