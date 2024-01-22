#include <vector>
using namespace std;

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int val = 0;
        for(auto& e : nums) val^=e;
        return val;
    }
};