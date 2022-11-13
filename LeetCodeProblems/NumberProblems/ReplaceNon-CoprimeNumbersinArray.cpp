#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int val = nums[i];
            while(!st.empty() && gcd(st.top(),val)!=1)
            {
                val = lcm(val,st.top());
                st.pop();
            }
            st.push(val);
        }
        return createRes();
    }
    
private:
    vector<int> createRes()
    {
        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    stack<int> st;
};