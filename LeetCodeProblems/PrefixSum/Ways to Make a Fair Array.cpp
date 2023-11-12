#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;
        vector<int> po(sz+2,0);
        vector<int> pe(sz+2,0);
        for(int i=0;i<sz;i++)
        {
            if(i%2==0)
            {
                pe[i+2]=nums[i]+pe[i];
                po[i+2]=po[i+1];
            }
            else
            {
                pe[i+2]=pe[i+1];
                po[i+2]=nums[i]+po[i];
            }
        }
        for(int i=0;i<sz;i++)
        {
            int pro = po[i+1]+pe[sz+1]-pe[i+2];
            int pre = pe[i+1]+po[sz+1]-po[i+2];
            if(pro==pre) res++;
        }
        return res;
    }
};