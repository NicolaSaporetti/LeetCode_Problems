#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz);
        vector<int> l = nums;
        vector<int> r = nums;
        for(int i=1;i<sz;i++) l[i]=l[i-1]*nums[i];
        for(int i=sz-2;i>=0;i--) r[i]=r[i+1]*nums[i];
        for(int i=1;i<sz-1;i++) res[i]=l[i-1]*r[i+1];
        res[0]=r[1];
        res[sz-1]=l[sz-2];
        return res;
    }
};