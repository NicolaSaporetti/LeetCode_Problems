#include <vector>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums),end(nums));
        int mindiff = 0;
        int maxdiff = INT_MAX;
        int result = INT_MAX;
        while(mindiff<=maxdiff)
        {
            int mid = mindiff+(maxdiff-mindiff)/2;
            if(p<=formePairs(nums,mid))
            {
                maxdiff= mid-1;
                result = mid;
            }
            else mindiff = mid+1;
        }
        return result;
    }
private:
    int formePairs(vector<int>& nums, int mid)
    {
        int pos = 0;
        int pairs = 0;
        while(pos+1<nums.size())
        {
            if(nums[pos+1]-nums[pos]<=mid)
            {
                pairs++;
                pos+=2;
            }
            else pos++;
        }
        return pairs;
    }
};