#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        int left = 0;
        for(int i=0;i<sz;i++) left+=(gas[i]-cost[i]);
        if(left<0) return -1;
        else
        {
            int left = gas[0];
            int res = 0;
            for(int i=0;i<sz-1;i++)
            {
                if(left-cost[i]<0)
                {
                    res = i+1;
                    left = gas[i+1];
                }
                else left=left-cost[i]+gas[i+1];
            }
            return res;
        }
    }
};