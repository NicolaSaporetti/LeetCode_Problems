#include <vector>
using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int res = 0;
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            map<int,int> m;
            for(int j=i;j<sz;j++)
            {
                if(m.count(nums[j])==0)
                {
                    m[nums[j]]=nums[j];
                    auto it = m.find(nums[j]);
                    if(next(it)!=m.end() && next(it)->first==nums[j]+1)
                    {
                        m[nums[j]]=next(it)->second;
                        m.erase(next(it));
                    }
                    if(it!=m.begin())
                    {
                        if(prev(it)->second+1>=nums[j]) 
                        {
                            prev(it)->second = max(prev(it)->second,m[nums[j]]);
                            m.erase(nums[j]);
                        }
                    }
                }
                res+=m.size()-1;
            }
        }
        return res;
    }
};