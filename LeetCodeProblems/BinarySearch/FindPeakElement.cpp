#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low<high) {
            int mid = (high+low)/2;
			if (nums[mid] > nums[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};