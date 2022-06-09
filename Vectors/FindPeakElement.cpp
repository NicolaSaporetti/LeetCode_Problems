#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(low<=high) {
            mid = (high+low)/2;
			
            if((mid-1<0 || nums[mid]>nums[mid-1] )  && (mid+1>=nums.size() || nums[mid]>nums[mid+1])) {
                return mid;
            }
            
            else if(nums[mid+1]>nums[mid]) {
                low = mid+1;
            }
            
            else {
                high = mid-1;
            }
        }
        
        return -1;
    }
};