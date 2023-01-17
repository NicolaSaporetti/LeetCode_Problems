#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = count_if(nums.begin(),nums.end(),[&](int num){return num>0;});
        int neg = count_if(nums.begin(),nums.end(),[&](int num){return num<0;});
        return max(pos,neg);
    }
};