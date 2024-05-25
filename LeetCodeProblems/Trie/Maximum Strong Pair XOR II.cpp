#include <vector>
#include "BinaryTrie.cpp"
using namespace std;

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int sz = nums.size();
        int i = 0;
        Trie t;
        int res = 0;
        for(int j=0;j<sz;j++)
        {
            for(;i<sz && nums[j]*2>=nums[i];i++) t.insert(nums[i]);
            res = max(res, t.find(nums[j])^nums[j]);
            t.erase(nums[j]);
        }
        return res;
    }
};