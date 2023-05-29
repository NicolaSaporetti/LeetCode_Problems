#include <stack>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        string res;
        for(auto& e : s)
        {
            if(!st.empty())
            {
                if(e=='B' && st.top()=='A') st.pop();
                else if(e=='D' && st.top()=='C') st.pop();
                else st.push(e);
            }
            else st.push(e);
        }
        return st.size();
    }
};