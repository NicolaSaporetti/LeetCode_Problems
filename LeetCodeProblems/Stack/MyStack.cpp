#include <stack>
using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        myS.push(val);
        if(myS2.empty() ||(!myS2.empty() && val<=myS2.top())) myS2.push(val);
    }
    
    void pop() {
        if(myS.top()==myS2.top()) myS2.pop();
        myS.pop();
    }
    
    int top() {
        return myS.top();
    }
    
    int getMin() {
        return myS2.top();
    }
private:
    stack<int> myS;
    stack<int> myS2;
};