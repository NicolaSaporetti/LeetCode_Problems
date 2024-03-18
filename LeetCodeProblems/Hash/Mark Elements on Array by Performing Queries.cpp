#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        map<int,set<int>> m;
        int ele = nums.size();
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum+=(long long)nums[i];
            m[nums[i]].insert(i);
        }
        vector<long long> r;
        for(auto el : queries)
        {
            int e = el[0];
            int k = el[1];
            if(m.count(nums[e])>0 && m[nums[e]].find(e)!=m[nums[e]].end())
            {
                m[nums[e]].erase(e);
                sum-=(long long) nums[e];
                if(m[nums[e]].empty()) m.erase(nums[e]);
                ele--;
            }
            for(int i=0;i<k && ele>0;i++)
            {
                auto it = m.begin();
                int it2 = *it->second.begin();
                sum-=nums[it2];
                it->second.erase(it2);
                if(it->second.size()==0) m.erase(it);
                ele--;
            }
            r.push_back(sum);
        }
        return r;
    }
};