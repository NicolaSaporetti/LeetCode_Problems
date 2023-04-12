#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string result;
        for(int i=0; i<s.size();i++)
        {
            if(st.empty() || s[i]!=st.top()) st.push(s[i]);
            else st.pop();
        }
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(begin(result),end(result));
        return result;
    }
};