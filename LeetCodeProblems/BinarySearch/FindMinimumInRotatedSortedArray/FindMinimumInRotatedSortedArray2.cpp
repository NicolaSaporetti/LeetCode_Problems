using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int r= nums.size()-1;
        int l=0;
        while(nums[l]>=nums[r] && l<r)
        {
            int mid = l + (r-l) / 2;
            if((nums[l] == nums[r]))
            {
                l++;
                r--;
            }
            else if(nums[r] < nums[mid]) l=mid+1;
            else r=mid;
        }
        return min(nums[l],nums[0]);
    }
};