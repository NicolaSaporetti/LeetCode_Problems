#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<pair<long long,long long>>> m;
        vector<long long> r(nums.size());
        for(long long i=0;i<nums.size();i++)
        {
            
            if(m.count(nums[i])>0) m[nums[i]].push_back({m[nums[i]].back().first+i,i});
            else m[nums[i]].push_back({i,i});
        }
        for(auto& [k,v] : m)
            for(int i=0;i<v.size();i++)
            {
                long long el = v[i].second;
                long long va = v[i].first;
                long long res1 = (i+1)*el-va;
                long long res2 = v.back().first-va-(v.size()-1-i)*el;
                r[el]=res1+res2;
            }
        return r;
    }
};