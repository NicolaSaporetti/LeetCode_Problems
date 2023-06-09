#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> m;
        int res = 0;
        for(auto& e : nums) m[e]++;
        for(auto it = m.rbegin();it!=m.rend();it++)
        {
            if(next(it)!=m.rend())
            {
                res+=it->second;
                next(it)->second+=it->second;
            }
            
        }
        return res;
    }
};