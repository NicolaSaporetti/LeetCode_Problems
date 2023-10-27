#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        map<int,int> m;
        m[nums[0]]++;
        for(int i=1;i<nums.size()-1;i++)
        {
            int ne = m.rbegin()->first+nums[i];
            m[ne]++;
            nums[i]=ne;
            if(i-k>=0)
            {
                int el = nums[i-k];
                m[el]--;
                if(m[el]==0) m.erase(el);
            }
        }
        return m.rbegin()->first+nums.back();
    }
};