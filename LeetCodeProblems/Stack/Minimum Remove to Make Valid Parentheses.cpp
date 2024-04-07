#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        stack<pair<char,int>> st;
        int pos = 0;
        for(auto e : s)  if(e=='(' || e==')') pos++;
        vector<bool> valid(pos);
        pos = 0;
        for(auto e : s)
        {
            if(e=='(') st.push({e,pos++});
            else if(e==')')
            {
                if(st.empty())
                {
                    valid[pos++] = false;
                }
                else
                {
                    valid[st.top().second]=true;
                    st.pop();
                    valid[pos++]=true;
                }
            }
        }
        while(!st.empty())
        {
            valid[st.top().second]=false;
            st.pop();
        }
        string r;
        pos = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]==')')
            {
                if(valid[pos++]) r.push_back(s[i]);
            }
            else r.push_back(s[i]);
        }
        return r;
    }
};