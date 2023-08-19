#include <stack>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if(x>=y)
        {
            res+=remove(s,x,"ab");
            res+=remove(s,y,"ba");
        }
        else
        {
            res+=remove(s,y,"ba");
            res+=remove(s,x,"ab");
        }
        return res;
    }
private:
    int remove(string& s, int x,string pat)
    {
        int p = 0;
        stack<char> st;
        for(auto& e : s)
        {
            if(st.empty() || st.top()!=pat[0] || (st.top()==pat[0] && pat[1]!=e)) st.push(e);
            else
            {
                st.pop();
                p+=x;
            }
        }
        s = {};
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        reverse(begin(s),end(s));
        return p;
    }
};