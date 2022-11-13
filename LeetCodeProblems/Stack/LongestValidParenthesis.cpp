#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxsize = 0;
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(') st.push(0);
            else
            {
                int val = 0;
                if(!st.empty())
                {
                    if(st.top()!=0)
                    {
                        val = st.top();
                        st.pop();
                    }
                    if(!st.empty())
                    {
                        val+=2;
                        st.pop();
                        if(!st.empty() && st.top()!=0) st.top()+=val;
                        else st.push(val);
                        maxsize = max(maxsize, st.top());
                    }
                }
            }
        }
        return maxsize;
    }
};