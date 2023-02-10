#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        sz = nums.size();
        buildPrefix(nums);
        res = (prefix[sz]%2==0)? tochange[prefix[sz]/2] : 0;
        computeVectorMinusLast(nums,k);
        computeLast(nums,k);        
        return res;
    }
private:
    void buildPrefix(vector<int>& nums)
    {
        prefix.resize(sz+1,0);
        
        for(int i=0;i<sz-1;i++)
        {
            prefix[i+1]=prefix[i]+(long long)(nums[i]);
            tochange[prefix[i+1]]++;
        }
        prefix[sz]=prefix[sz-1]+(long long)(nums[sz-1]);
    }
    
    void computeVectorMinusLast(vector<int>& nums, int k)
    {
        for(int i=0;i<sz-1;i++)
        {
            int diff = k-nums[i];
            int newLast = prefix[sz]+diff;
            unchanged[prefix[i+1]+diff]++;
            tochange[prefix[i+1]]--;
            if(newLast%2==0)
            {
                int newTot = unchanged[newLast/2]+tochange[newLast/2-diff];
                res = max(res,newTot);
            }
            unchanged[prefix[i+1]+diff]--;
            unchanged[prefix[i+1]]++;
        }
    }
    
    void computeLast(vector<int>& nums, int k)
    {
        int diff = k-nums[sz-1];
        int newLast = prefix[sz]+diff;
        if(newLast%2==0)
        {
            int newTot = unchanged[newLast/2]+tochange[newLast/2-diff];
            res = max(res,newTot);
        }
    }
    
    int sz;
    int res;
    unordered_map<long long, int> unchanged;
    unordered_map<long long, int> tochange;
    vector<long long> prefix;
};