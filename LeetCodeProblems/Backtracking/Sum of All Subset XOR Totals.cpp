#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        computeSets(nums,0);
        return result;
    }
private:
    void computeSets(vector<int>& nums, int start)
    {
        if(start>=nums.size()) return;
        else
        {
            for(int i=start;i<nums.size();i++)
            {
                num.push_back(nums[i]);
                computeXor();
                computeSets(nums,i+1);
                num.pop_back();
            }
        }
    }
    
    void computeXor()
    {
        int res = num[0];
        for(int i=1;i<num.size();i++) res^=num[i];
        result+=res;
    }
    
    vector<int> num;
    int result;
};