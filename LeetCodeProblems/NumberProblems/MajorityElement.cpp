#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int value = 1;
        int elem = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==elem) value++;
            else if(value) value--;
            else
            {
                value = 1;
                elem = nums[i];
            }
        }
        return elem;
    }
};