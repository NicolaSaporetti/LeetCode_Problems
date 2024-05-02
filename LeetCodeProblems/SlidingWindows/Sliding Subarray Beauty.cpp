#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> v(101,0);
        vector<int> r(nums.size()-k+1);
        for(int i=0;i<k-1;i++) v[nums[i]+50]++;
        for(int i=k-1;i<nums.size();i++)
        {
            v[nums[i]+50]++;
            int left = x;
            for(int j=0;j<50;j++)
            {
                if(!v[j]) continue;
                left-=v[j];
                if(left<=0)
                {
                    r[i-k+1]=j-50;
                    break;
                }
            }
            v[nums[i-k+1]+50]--;
        }
        return r;
    }
};