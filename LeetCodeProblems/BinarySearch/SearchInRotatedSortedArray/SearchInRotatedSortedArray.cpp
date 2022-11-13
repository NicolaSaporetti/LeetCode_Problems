#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r= nums.size()-1;
        int l=0;
        checkRotatedArray(nums,l,r,target);
        return binarySearch(nums,l,r,target);
    }
    
private:
    void checkRotatedArray(vector<int>& nums, int& l, int& r, int target)
    {
        int mid=0;
        while(nums[l]>nums[r] && l<r)
        {
            mid=l+(r-l)/2;
            if(nums[r] < nums[mid]) l=mid+1;
            else r=mid;
        }
        if(target<=nums[nums.size()-1]) r=nums.size()-1;
        else{
            r=l;
            l=0;
        }
    }
    
    int binarySearch(vector<int>& nums, int l, int r, int t)
    {
        int mid = 0;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]<t) l=mid+1;
            else r=mid;
        }
        return (nums[l]==t)? l : -1;
    }
};