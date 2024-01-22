#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int v = 0;
        for(auto e : nums) v^=e;
        int r = 0;
        for(int i=0;i<31;i++)
        {
            bool b1=(1<<i)&v;
            bool b2=(1<<i)&k;
            if(b1!=b2) r++;
        }
        return r;
    }
};