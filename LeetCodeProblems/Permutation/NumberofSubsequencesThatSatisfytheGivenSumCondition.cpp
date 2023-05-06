#include <vector>
using namespace std;

class Solution {
public:    
    int numSubseq(vector<int>& nums, int target) {
        const int mod=1e9+7;
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=1;
        for(int i=1;i<n;i++) prefix[i]=(prefix[i-1]*2)%mod;
        int res=0;
        for(int i=0;i<n;i++){
            int val_rest = target-nums[i];
            int pos=upper_bound(begin(nums)+i,end(nums),val_rest)-nums.begin();
            if(pos>i) res = (res+prefix[pos-i-1])%mod;
        }
        return res;
    }
};