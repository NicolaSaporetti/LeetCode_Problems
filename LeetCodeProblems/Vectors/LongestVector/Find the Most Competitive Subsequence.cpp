#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        vector<int> res;
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            while(st.size()>0 && st.back()>nums[i] && st.size()+sz-1-i>=k) st.pop_back();
            st.push_back(nums[i]);
        }
        st.resize(k);
        return st;
    }
};