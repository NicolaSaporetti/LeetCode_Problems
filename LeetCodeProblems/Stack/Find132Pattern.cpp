#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;     
        int curMin = nums[0];
        for(int i = 1; i < n; i++){
            while(!st.empty() && nums[i] >= st.top().first){
                st.pop();
            }
            if(!st.empty() && nums[i] > st.top().second){
                return true;
            }
            st.push({nums[i], curMin});
            curMin = min(curMin, nums[i]);
        }
        return false;
    }
};