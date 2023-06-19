#include <vector>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int min = *min_element(begin(nums),end(nums));
        int max = *max_element(begin(nums),end(nums));
        for(auto& e : nums) if(e!=min && e!=max) return e;
        return -1;
    }
};