#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> res;
        for(int i=0;i<k;i++) m[nums[i]]++;
        for(int i=k;i<nums.size();i++)
        {
            res.push_back(m.rbegin()->first);
            m[nums[i]]++;
            m[nums[i-k]]--;
            if(!m[nums[i-k]]) m.erase(nums[i-k]);
        }
        res.push_back(m.rbegin()->first);
        return res;
    }
};