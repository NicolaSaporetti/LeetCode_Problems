#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string result;
        for(auto& c : s)
        {
            if(st.empty() || st.top().first!=c) st.push({c,1});
            else st.push({c,st.top().second+1});
            if(!st.empty() && st.top().second==k)
            {
                for(int i=0;i<k;i++) st.pop();
            }
        }
        while(!st.empty())
        {
            result.push_back(st.top().first);
            st.pop();
        }
        reverse(begin(result),end(result));
        return result;
    }
};