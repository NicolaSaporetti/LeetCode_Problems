#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            int dest = nums[i];
            int pos = i;
            if(pos!=dest-1) nums[i]=-1;
            while(pos!=dest-1 && dest!=-1)
            {
                if(nums[dest-1]==dest) res.push_back(dest);;
                pos=dest-1;
                swap(dest,nums[dest-1]);
            }
        }
        return res;
    }
};