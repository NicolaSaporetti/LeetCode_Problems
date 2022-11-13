#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solutions;
        sort(nums.begin(),nums.end());
        for(int l=0;l<nums.size()-2;l++)
        {
            if(l>0 && nums[l]==nums[l-1]) continue;
            int m=l+1;
            int r = nums.size()-1;
            while(m<r)
            {
                int sum = nums[l]+nums[m]+nums[r];
                if(sum == 0) {
                    solutions.push_back({nums[l], nums[m], nums[r]});
                    while (m < r && nums[m] == nums[m+1]) m++;
                    while (m < r && nums[r] == nums[r-1]) r--;
                    m++;
                    r--;
                }
                else if(sum < 0)
                {
                    while (m < r && nums[m] == nums[m+1]) m++;
                    m++;
                }
                else
                {
                    while (m < r && nums[r] == nums[r-1]) r--;
                    r--;
                }
            }
        }
        return solutions;
    }
};