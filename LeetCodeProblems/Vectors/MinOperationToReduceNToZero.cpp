#include <vector>
using namespace std;
class Solution {  
public:
    int minOperations(vector<int>& nums, int x) {
        if(accumulate(begin(nums),end(nums),0)==x) return nums.size();
        sz = nums.size();
        vector<int> left = setupLeft(nums);
        vector<int> right =  setupRight(nums);
        int oper = sz+1;
        for(int i=0;i<sz+1;i++)
        {
            auto it = lower_bound(begin(right),end(right),x-left[i]);
            if(it!=end(right) && *it+left[i]==x)
            {
                int d = it-begin(right);
                oper = min(oper,d+i);
            }
        }
        return (oper==sz+1)? -1 : oper;
    }
private:
    vector<int> setupLeft(vector<int>& nums)
    {
        vector<int> l(sz+1,0);
        for(int i=0;i<sz;i++) l[i+1]=l[i]+nums[i];
        return l;
    }
    
    vector<int> setupRight(vector<int>& nums)
    {
        vector<int> r(sz+1,0);
        for(int i=sz-1;i>=0;i--) r[sz-i]=r[sz-1-i]+nums[i];
        return r;
    }

    int sz;
};