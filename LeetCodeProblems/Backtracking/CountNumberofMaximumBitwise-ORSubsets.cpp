#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        computeSub(0,0,nums);
        return m.rbegin()->second;
    }
private:
    void computeSub(int val, int start, vector<int>& nums)
    {
        if(start>=nums.size())
        {
            m[val]++;
        }
        else
        {
            for(int i=start;i<nums.size();i++)
            {
                computeSub(val|nums[i],i+1,nums);
            }
            computeSub(val,nums.size(),nums);
        }
    }
    
    map<int,int> m;
};