#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        sz = nums.size();
        mid = ((sz+1)*sz/2+1)/2;
        int r = sz;
        int minv = 1;
        int maxv = sz;
        while(minv<=maxv)
        {
            int avg = (minv+maxv)/2;
            if(isMed(avg, nums))
            {
                r=avg;
                maxv = avg-1;
            }
            else minv = avg+1;
        }
        return r;
    }
private:
    bool isMed(int avg, vector<int>& nums)
    {
        unordered_map<int, int> mp;
        int i=0;
        long long r=0;
        for(int j=0;j<sz;j++)
        {
            mp[nums[j]]++;
            while(mp.size()>avg && i<=j)
            {
                if(--mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            r += (long long)(j-i+1);
        }
        return r>=mid;
    }
    long long sz;
    long long mid;
};