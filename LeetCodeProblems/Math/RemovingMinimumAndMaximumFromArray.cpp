#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int sz = nums.size();
        int min_pos = min_element(nums.begin(),nums.end())-nums.begin();
        int max_pos = max_element(nums.begin(),nums.end())-nums.begin();
        int minRemoval = min(min(max(min_pos,max_pos)+1,max(sz-max_pos,sz-min_pos)),min(min_pos,max_pos)+1+sz-(max(min_pos,max_pos)));
        return minRemoval;
    }
};