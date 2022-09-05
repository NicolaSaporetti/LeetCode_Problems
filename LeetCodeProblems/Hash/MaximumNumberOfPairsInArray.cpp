#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> res(2,0);
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            res[1]+=(it->second%2);
            res[0]+=(it->second/2);
        }
        return res;
    }
};