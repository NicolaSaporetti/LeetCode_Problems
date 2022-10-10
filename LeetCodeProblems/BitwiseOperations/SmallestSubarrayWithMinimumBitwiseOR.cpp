#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        vector<int> c(31,0);
        vector<int> m(31,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<31;j++)
            {
                if(1<<j&nums[i]) m[j]++;
            }
        }
        int rz = 0;
        for(int i=0;i<nums.size();i++)
        {
            while(!match(c,m) && rz!=nums.size())
            {
                for(int j=0;j<31;j++)
                {
                    if(1<<j&nums[rz]) c[j]++;
                }
                rz++;
            }
            res[i]=max(rz-i,1);
            for(int j=0;j<31;j++)
            {
                if(1<<j&nums[i])
                {
                    c[j]--;
                    m[j]--;
                }
            }
        }
        return res;
    }
    
    bool match(vector<int>& c, vector<int>& m)
    {
        for(int j=0;j<31;j++)
        {
            if(m[j]>=1 && c[j]==0) return false;
        }
        return true;
    }
};