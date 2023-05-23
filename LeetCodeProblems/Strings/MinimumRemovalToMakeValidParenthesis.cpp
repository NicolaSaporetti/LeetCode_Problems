#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push({s[i],i});
            else if(s[i]==')')
            {
                if(!st.empty() && st.top().first=='(') st.pop();
                else st.push({s[i],i});
            }
        }
        vector<int> v;
        while(!st.empty()) 
        {
            v.push_back(st.top().second);
            st.pop();
        }
        int j = v.size()-1;
        for(int i=0;i<s.size();i++)
        {
            if(j>=0 && v[j]==i) j--;
            else res.push_back(s[i]);
        }
        return res;
    }
};