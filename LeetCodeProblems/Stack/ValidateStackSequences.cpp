#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int iP = 0;
        int iPop = 0;
        while(iP<pushed.size() && iPop<popped.size())
        {
            if(s.empty() || s.top()!=popped[iPop]) s.push(pushed[iP++]);
            while(!s.empty() && s.top()==popped[iPop])
            {
                s.pop();
                iPop++;
            }
        }
        return s.empty();
    }
};