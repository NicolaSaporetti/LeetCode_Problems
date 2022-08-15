#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int f(int ind,map<int,int>& mp,int maxIndex, vector<int>& dp){
        if(ind>maxIndex) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int notdeleted = f(ind+1,mp,maxIndex,dp);
        int deleted = ind*mp[ind] + f(ind+2,mp,maxIndex,dp);
        return dp[ind] = max(notdeleted,deleted);
    }
   
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto a: nums){
            mp[a]++;
        }
        int maxIndex = *max_element(nums.begin(),nums.end());
        int minIndex = *min_element(nums.begin(),nums.end());
        vector<int> dp(maxIndex+1,-1);
        return f(minIndex,mp,maxIndex,dp); 
    }
};