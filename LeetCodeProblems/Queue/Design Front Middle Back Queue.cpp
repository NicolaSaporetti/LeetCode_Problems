#include <deque>
#include <stack>
using namespace std;

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        q.push_front(val);
    }
    
    void pushMiddle(int val) {
        stack<int> st;
        int n = (q.size()+1)/2;
        for(int i=0;i<n;i++)
        {
            st.push(q.back());
            q.pop_back();
        }
        q.push_back(val);
        while(!st.empty())
        {
            q.push_back(st.top());
            st.pop();
        }
    }
    
    void pushBack(int val) {
        q.push_back(val);
    }
    
    int popFront() {
        if(q.size()==0) return -1;
        int e = q.front();
        q.pop_front();
        return e;
    }
    
    int popMiddle() {
        if(q.size()==0) return -1;
        stack<int> st;
        int n = q.size()/2+1;
        for(int i=0;i<n;i++)
        {
            st.push(q.back());
            q.pop_back();
        }
        int e =st.top();
        st.pop();
        while(!st.empty())
        {
            q.push_back(st.top());
            st.pop();
        }
        return e;
    }
    
    int popBack() {
        if(q.size()==0) return -1;
        int e = q.back();
        q.pop_back();
        return e;
    }
    
    deque<int> q;
};