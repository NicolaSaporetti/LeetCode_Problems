#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> v;
        int sz = nums.size();
        for(int i=0;i<sz;i++) v.push_back({nums[i],i});
        sort(begin(v),end(v));
        vector<int> res(sz,0);
        vector<int> r(sz,0);
        for(int i=0;i<sz;i++) res[i]=v[i].second;
        int s =0;
        for(int i=1;i<sz;i++)
        {
            if(v[i].first>v[i-1].first+limit)
            {
                sort(begin(res)+s,begin(res)+i);
                s=i;
            }
        }
        sort(begin(res)+s,begin(res)+sz);
        for(int i=0;i<sz;i++)
        {
            r[res[i]]=v[i].first;
        }
        return r;
    }
};