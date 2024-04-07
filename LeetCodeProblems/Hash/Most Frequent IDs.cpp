#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        map<long long,set<int>> f;
        vector<long long> res;
        map<int,long long> m;
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            long long pf = m[nums[i]];
            m[nums[i]]+=freq[i];
            long long nf = pf+freq[i];
            f[pf].erase(nums[i]);
            f[nf].insert(nums[i]);
            if(f[pf].empty()) f.erase(pf);
            auto it = f.rbegin();
            res.push_back(it->first);
        }
        return res;
    }
};