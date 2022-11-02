#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> s;
        vector<int> res(2,0);
        for(auto i : nums)
        {
            if(s.find(i)!=s.end()) res[0]=i;
            s.insert(i);
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(s.find(i)==s.end())
            {
                res[1]=i;
                break;
            }
        }
        return res;
    }
};