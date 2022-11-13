#include <priority_queue>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!mxh.empty() && num>mxh.top()) mxh.push(num);
        else if(!mnh.empty() && num<mnh.top()) mnh.push(num);
        else mxh.push(num);
        if(mxh.size()>mnh.size()+1)
        {
            mnh.push(mxh.top());
            mxh.pop();
        }
        if(mnh.size()>mxh.size()+1)
        {
            mxh.push(mnh.top());
            mnh.pop();
        }
    }
    
    double findMedian() {
        if(mxh.size()==mnh.size()) return (double)(mxh.top()+mnh.top())/2.0;
        else {
            if(mxh.size()>mnh.size()) return (double) mxh.top();
            else return (double) mnh.top();
        }
    }
private:
    priority_queue<int> mnh;
    priority_queue<int, vector<int>, greater<int>> mxh;
};