#include <vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int sz = nums.size();
        int el = -1;
        int f = 0;
        for(auto& e : nums)
        {
            if(f==0)
            {
                el = e;
                f=1;
            }
            else if(el==e)f++;
            else f--;
        }
        f = 0;
        for(auto& e : nums) if(e==el) f++;
        if(sz%2==1 && f==(sz+1)/2) return -1;
        int c = 0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]==el) c++;
            else c--;
            if(c>0) return i;
        }
        return -1;
    }
};