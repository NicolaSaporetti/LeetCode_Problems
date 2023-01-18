#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int arr_sum = 0;
        int temp_maxsum = 0,subarr_maxsum = INT_MIN;
        int temp_minsum = 0,subarr_minsum = INT_MAX;
        for(int i = 0;i<n;i++){
            arr_sum += nums[i];
            
            temp_maxsum += nums[i];
            subarr_maxsum = max(subarr_maxsum,temp_maxsum);
            if(temp_maxsum<0) temp_maxsum = 0;
            
            temp_minsum += nums[i];
            subarr_minsum = min(subarr_minsum,temp_minsum);
            if(temp_minsum>0) temp_minsum = 0;
        }
        
        if(arr_sum==subarr_minsum) return subarr_maxsum;
        return max(subarr_maxsum, (arr_sum - subarr_minsum) );
    }
};