#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(first.empty())
        {
            while(!second.empty())
            {
                first.push(second.top());
                second.pop();
            }
        }
        first.push(x);
    }
    
    int pop() {
        if(second.empty())
        {
            while(!first.empty())
            {
                second.push(first.top());
                first.pop();
            }
        }
        int value = second.top();
        second.pop();
        return value;
    }
    
    int peek() {
        if(second.empty())
        {
            while(!first.empty())
            {
                second.push(first.top());
                first.pop();
            }
        }
        return second.top();
    }
    
    bool empty() {
        return first.empty() && second.empty();
    }
    
private:
    stack<int> first;
    stack<int> second;
};