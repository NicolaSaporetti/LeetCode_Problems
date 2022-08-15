#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find_ans(vector<long long>&prefix,int k,int idx,int num){
        
        int ans=0;
        int s=0;
        int e=idx;
    
        while(s<=e){
            int mid=(s+e)/2;
            long long sum=prefix[idx+1]-prefix[mid];
            long long operation=1LL*(idx-mid+1)*num-sum;
            if(operation<=(1LL*k)){
                ans=max(ans,(idx-mid+1));
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int maxFrequency(vector<int>& nums, int k) {
    
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        map<int,int>mp;
       vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=n-1;i>=0;i--){
            mp[nums[i]]++;
            int cur=find_ans(prefix,k,i-1,nums[i]);
            ans=max(ans,cur+mp[nums[i]]);
            
        }
        return ans;
    }
};