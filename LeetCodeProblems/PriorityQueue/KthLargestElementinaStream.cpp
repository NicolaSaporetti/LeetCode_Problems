#include <priority_queue>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : dist(k) {
        for(auto& e : nums) top.push(e);
    }
    
    int add(int val) {
        top.push(val);
        while(top.size()>dist)
        {
            bot.push(top.top());
            top.pop();
        }
        return top.top();
    }
private:
    priority_queue<int> bot;
    priority_queue<int,vector<int>,greater<int>> top;
    int dist;
};