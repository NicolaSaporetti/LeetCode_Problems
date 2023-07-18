#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> r(sz,sz-1);
        vector<int> l(sz,0);
        stack<int> st;
        int tot = 0;
        for(int i=0;i<sz;i++)
        {
            if(st.empty()) st.push(i);
            else
            {
                while(!st.empty() && nums[st.top()]>nums[i])
                {
                    r[st.top()] = i-1;
                    st.pop();
                }
                st.push(i);
            }
        }
        st = {};
        for(int i=sz-1;i>=0;i--)
        {
            if(st.empty()) st.push(i);
            else
            {
                while(!st.empty() && nums[st.top()]>nums[i])
                {
                    l[st.top()] = i+1;
                    st.pop();
                }
                st.push(i);
            }
        }
        for(int i=0;i<sz;i++)
        {
            if(l[i]<=k && r[i]>=k) tot = max(tot,(r[i]-l[i]+1)*nums[i]);
        }
        return tot;
    }
};