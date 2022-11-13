#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> solutions;
        if(nums.size()<4) return solutions;
        sort(nums.begin(),nums.end());
        for(int l=0;l<nums.size()-3;l++)
        {
            if(l > 0 && nums[l]==nums[l-1]) continue;
            for(int r=nums.size()-1;r>l+2;r--)
            {
                if(r < nums.size()-1 && nums[r]==nums[r+1]) continue;
                int m=l+1;
                int m2 = r-1;
                while(m<m2)
                {
                    long long sum = (long long)nums[l]+(long long)nums[m]+(long long)nums[m2]+(long long)nums[r];
                    if(sum == (long long)target) {
                        solutions.push_back({nums[l], nums[m], nums[m2], nums[r]});
                        while (m < m2 && nums[m] == nums[m+1]) m++;
                        while (m < m2 && nums[m2] == nums[m2-1]) m2--;
                        m++;
                        m2--;
                    }
                    else if(sum < (long long)target) m++;
                    else m2--;
                }
            }
        }
        return solutions;
    }
};