#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) myS.insert(nums[i]);
        return computeLongestSequence();
    }
    
private:
    int computeLongestSequence()
    {
        int prev = INT_MIN;
        int tot = 0;
        int res = 0;
        for(auto e : myS)
        {
            if(e-1!=prev)
            {
                res = max(res,tot);
                tot=1;
            }
            else tot++;
            prev = e;
        }
        return max(res,tot);
    }
    
    set<int> myS;
};