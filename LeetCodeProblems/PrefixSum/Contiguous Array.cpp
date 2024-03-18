#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> dif;
        dif[0]=0;
        int z = 0;
        int o = 0;
        int r = 0;
        for(auto e : nums)
        {
            if(e==0) z++;
            else o++;
            int d = z-o;
            if(dif.count(d)>0) r = max(r,(z-dif[d])*2);
            else dif[d]=z;
        }
        return r;
    }
};