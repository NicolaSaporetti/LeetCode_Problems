#include <map>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> m;
        int mres = 0;
        int res = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0) m[nums[i]]++;
        }
        for(auto it =m.begin();it!=m.end();it++)
        {
            if(it->second>mres)
            {
                mres = it->second;
                res = it->first;
            }
        }
        return res;
    }
};