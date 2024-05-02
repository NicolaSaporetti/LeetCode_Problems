#include <vector>
using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int r = 0;
        for(int i=n/2-1;i>=0;i--)
        {
            int v1 = i*2+1;
            int v2 = i*2+2;
            cost[i]+=max(cost[v1],cost[v2]);
            r+=abs(cost[v1]-cost[v2]);
        }
        return r;
    }
};