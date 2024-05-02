#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int r = 0;
        int res = 0;
        for(auto e : nums) r^=e;
        for(int i=0;i<31;i++) if((k&(1<<i))!=(r&(1<<i))) res++;
        return res;
    }
};