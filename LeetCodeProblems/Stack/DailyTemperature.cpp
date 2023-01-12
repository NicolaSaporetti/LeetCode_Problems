#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        vector<int> res(sz,0);
        stack<int> s;
        for(int i=0;i<sz;i++)
        {
            while(!s.empty() && temperatures[s.top()]<temperatures[i])
            {
                res[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};