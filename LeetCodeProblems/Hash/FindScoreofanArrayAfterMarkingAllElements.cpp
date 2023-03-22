#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;
        map<int,set<int>> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].insert(i);
        }
        while(!m.empty())
        {
            auto it=m.begin();
            res+=it->first;
            int index = *it->second.begin();
            it->second.erase(index);
            if(m[nums[index]].empty()) m.erase(nums[index]);
            if(index-1>=0)
            {
                m[nums[index-1]].erase(index-1);
                if(m[nums[index-1]].empty()) m.erase(nums[index-1]);
            }
            if(index+1<nums.size())
            {
                m[nums[index+1]].erase(index+1);
                if(m[nums[index+1]].empty()) m.erase(nums[index+1]);
            }
        }
        return res;
    }
};