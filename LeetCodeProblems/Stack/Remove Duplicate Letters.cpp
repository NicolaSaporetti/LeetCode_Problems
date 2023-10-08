#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        stack<char> st;
        vector<int> v(26,0);
        vector<bool> sel(26,false);
        int sz = s.size();
        for(auto l : s) v[l-'a']++;
        for(int i=0;i<sz;i++)
        {
            if(!sel[s[i]-'a'])
            {
                while(!st.empty() && st.top()>=s[i] && v[st.top()-'a']>0)
                {
                    sel[st.top()-'a']=false;
                    st.pop();
                }
                st.push(s[i]);
                sel[s[i]-'a']=true;
            }
            v[s[i]-'a']--;
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};