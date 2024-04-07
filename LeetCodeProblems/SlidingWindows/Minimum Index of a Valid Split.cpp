#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int sz = nums.size();
        map<int,int> m;
        for(auto e : nums) m[e]++;
        map<int,int> f;
        for(auto [k,v] : m) f[v]=k;
        auto it = f.rbegin();
        if((sz%2==0 && it->first*2<=sz) || (sz%2==1 && it->first-1<=sz/2)) return -1;
        int n = 0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]==it->second) n++;
            else n--;
            if(n>0) return i;
        }
        return -1;
    }
};