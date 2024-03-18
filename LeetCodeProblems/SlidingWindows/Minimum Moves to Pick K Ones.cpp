#include <vector>
using namespace std;

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        sz = nums.size();
        vector<int> v;
        for(int i=0;i<sz;i++) if(nums[i]==1) v.push_back(i);
        v.push_back(1e6);
        reduceMaxChargesNeedeed(k,maxChanges,v.size()-1);
        if(!checkIfNotAllChargesNeedsToBeUsed(nums,k,maxChanges))
        {
            nt+=maxChanges*2;
            long long tot = 0;
            long long left = 0;
            long long right = 0;
            int leftp = 0;
            int rightp = 0;
            for(int i=0;i<k-maxChanges;i++)
            {
                tot+=v[rightp++];
                right++;
            }
            for(int i=1;i<sz;i++)
            {
                if(nums[i-1]==1)
                {
                    left++;
                    right--;
                }
                tot-=right;
                tot+=left;
                long long leftD = i-v[leftp];
                long long rightD = v[rightp]-i;
                if(leftD>rightD)
                {
                    left--;
                    right++;
                    leftp++;
                    rightp++;
                    tot+=rightD;
                    tot-=leftD;
                }
                res = min(res,tot);
            }
        }
        return res+nt;
    }
private:
    void reduceMaxChargesNeedeed(int& k, int& maxChanges, int size)
    {
        long long maxD = k-size;
        if(maxD>0)
        {
            k-=maxD;
            nt+=maxD*2;
            maxChanges-=maxD;
        }
    }

    bool checkIfNotAllChargesNeedsToBeUsed(vector<int>& nums, int k, int maxChanges)
    {
        for(int i=0;i<sz;i++)
        {
            long long tot = 0;
            int k1 = k;
            if(nums[i]==1) k1--;
            if(i-1>=0 && k1>0 && nums[i-1]==1)
            {
                k1--;
                tot++;
            }
            if(i+1<sz && k1>0 && nums[i+1]==1)
            {
                k1--;
                tot++;
            }
            if(k1<=maxChanges)
            {
                tot+=min(k1,maxChanges)*2;
                k1=0;
            }
            if(k1==0)
            {
                res = min(res,tot);
            }
        }
        return (res!=1e18);
    }

    long long nt = 0;
    long long res = 1e18;
    int sz;
};