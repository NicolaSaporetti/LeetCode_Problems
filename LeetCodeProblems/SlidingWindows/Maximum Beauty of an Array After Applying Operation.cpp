#include <vector>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int sz = nums.size();
        int res = 0;
        int mne = *min_element(begin(nums),end(nums));
        int mxe = *max_element(begin(nums),end(nums));
        for(int i=mne;i<=mxe;i++)
        {
            int l = lower_bound(begin(nums),end(nums),i-k)-begin(nums);
            int u = upper_bound(begin(nums),end(nums),i+k)-begin(nums);
            res = max(res, u-l);
        }
        return res;
    }
};