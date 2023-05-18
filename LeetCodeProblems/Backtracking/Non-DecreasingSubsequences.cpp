#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        func(0,nums);
        return vector(ans.begin(),ans.end());
        
    }
private:
    void func(int idx, vector<int>&nums){
        if(idx>=nums.size())
        {
            if(temp.size()>=2) ans.insert(temp);
            return ;
        }
        if(!temp.size() || nums[idx]>=temp.back())
        {
            temp.push_back(nums[idx]);
            func(idx+1,nums);
            temp.pop_back();
        }
        func(idx+1,nums); 
    }
    
    set<vector<int>>ans;
    vector<int>temp;
};