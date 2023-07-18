#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int sz = num.size();
        int notZeroLetters = 0;
        int start = 0;
        for(int i=0;i<sz && notZeroLetters<=k;i++)
        {
            if(num[i]!='0') notZeroLetters++;
            else
            {
                start = i+1;
                k-=notZeroLetters;
                notZeroLetters = 0;
            }
        }
        stack<char> st;
        for(int i=start;i<sz;i++)
        {
            if(st.empty()) st.push(num[i]);
            else
            {
                while(!st.empty() && st.top()>num[i] && k>0)
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        while(!st.empty())
        {
            if(k<=0) res.push_back(st.top());
            else k--;
            st.pop();
        }
        while(!res.empty() && res.back()=='0') res.pop_back();
        reverse(begin(res),end(res));
        return (res.size()==0)?"0": res;
    }
};