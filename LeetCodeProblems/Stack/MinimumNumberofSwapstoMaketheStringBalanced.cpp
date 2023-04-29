#include <stack>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto& e : s)
        {
            if(st.empty() || e=='[') st.push(e);
            else if(e==']' && st.top()=='[') st.pop();
            else st.push(e);
        }
        return st.size()/4+(st.size()%4/2);
    }
};