#include <vector>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sz = nums.size();
        sort(begin(nums),end(nums));
        compute(0,nums,k);
        return r;
    }
private:
    void compute(int s, vector<int>& nums, int k)
    {
        for(int i=s;i<sz;i++)
        {
            bool isOk = true;
            for(auto e : v)
                if(e+k==nums[i])
                {
                    isOk = false;
                    break;
                }
            if(isOk)
            {
                v.push_back(nums[i]);
                r++;
                compute(i+1,nums,k);
                v.pop_back();
            }
        }
    }

    int sz;
    vector<int> v;
    int r = 0;
}; 