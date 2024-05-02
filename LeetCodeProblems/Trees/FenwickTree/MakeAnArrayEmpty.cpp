#include <vector>
#include "FenwickTree.cpp"
using namespace std;

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<pair<int,int>> v;
        int sz = nums.size();
        for(int i=0;i<sz;i++) v.push_back({nums[i],i});
        sort(begin(v),end(v));
        FenwickTree ft(sz);
        int pos = 0;
        long long r = sz;
        for(int i=0;i<sz;i++)
        {
            int np = v[i].second;
            if(np>=pos) r+=np-pos-ft.sum(pos,np);
            else r+=sz-pos+np-ft.sum(pos,sz)-ft.sum(np);
            pos = np;
            ft.add(pos,1);
        }
        return r;
    }
};