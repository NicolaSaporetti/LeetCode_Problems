#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int mod=1e9+7;
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>prefix(n+11,0);
        prefix[1]=1LL;
        long long cnt=2LL;
        for(int i=1;i<=(n+9);i++)
        {
            prefix[i+1]=(prefix[i]+cnt)%mod;
            prefix[i+1]%=mod;
            cnt=(2LL*cnt)%mod;
        }
        long long ans=0;
        vector<int>temp;
        for(int i=0;i<n;i++){
            if((2*nums[i])<=target)ans=(ans+1LL)%mod;
            if(i==0)continue;
            int left=target-nums[i];
            if(left<=0)continue;
            int it=upper_bound(nums.begin(),nums.begin()+i,left)-nums.begin();
        
            if(it==0 or it>i)continue;
             it--;
           int start=i-it-1;
           int end=i-1;
     
                ll cur=(prefix[end+1]-prefix[start]+mod)%mod;
               
            ans=(ans+cur)%mod;
          
        }
        
        return (int)ans%mod;
        
    }
};