#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long t = target;
        int res = 0;
        int sz=nums.size();
        long long sum = 0;
        for(auto& e : nums) sum+=(long long)e;
        if(t>=sum)
        {
            res+=((t/sum)*sz);
            t%=sum;
        }
        if(t==0) return res;
        map<long long,int> m;
        m[0]=0;
        long long v = 0;
        for(int i=0;i<sz*2;i++)
        {
            v+=(long long)nums[i%sz];
            m[v]=i+1;
        }
        int d = INT_MAX;
        for(auto& [k,v] : m)
        {
            if(m.count(k+t)>0) d = min(d,m[k+t]-v);
        }
        return (d==INT_MAX)? -1 : res+d;
    }
};