#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int sz = nums.size();
        bool convDone = false;
        int i=1;
        for(;i<sz;i++) if(nums[i]<nums[i-1]) break;
        if(i<sz)
        {
            int temp = nums[i];
            nums[i]=nums[i-1];
            if(!isCorrect(nums))
            {
                nums[i]=temp;
                nums[i-1]=nums[i];
                if(!isCorrect(nums)) return false;
            }
        }
        return true;
    }
private:
    bool isCorrect(vector<int>& nums)
    {
        for(int j=1;j<nums.size();j++) if(nums[j]<nums[j-1]) return false;
        return true;
    }
};