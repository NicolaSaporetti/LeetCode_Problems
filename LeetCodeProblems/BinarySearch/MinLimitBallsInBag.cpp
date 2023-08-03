#include <vector>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        for(auto& e : nums) m[e]++;
        int minE = 1;
        int maxV = *max_element(begin(nums),end(nums));
        int res = maxV;
        while(minE<=maxV)
        {
            int avg = minE+(maxV-minE)/2;
            if(canDivide(avg,maxOperations))
            {
                res = avg;
                maxV = avg-1;
            }
            else minE = avg+1;
        }
        return res;
    }
private:
    bool canDivide(int avg, int maxOperations)
    {
        for(auto& [k,v] : m)
        {
            int div = k/avg+ ((k%avg==0) ? 0 : 1);
            maxOperations-=((div-1)*v);
            if(maxOperations<0) return false;
        }
        return true;
    }

    map<int,int> m;
};