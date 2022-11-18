using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int r= nums.size()-1;
        int l=0;
        int mid=0;
        while(nums[l]>nums[r] && l<r)
        {
            mid=l+(r-l)/2;
            if(nums[r] < nums[mid]) l=mid+1;
            else r=mid;
        }
        return nums[l];
    }
};