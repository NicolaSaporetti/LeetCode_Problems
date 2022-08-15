#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        vector<int> res(sz,0);
        stack<int> s;
        for(int i=sz-1;i>=0;i--)
        {
            while(!s.empty() && temperatures[s.top()]<=temperatures[i]) s.pop();
            if(!s.empty()) res[i]=s.top()-i;
            s.push(i);
        }
        return res;
    }
};