#include <vector>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCap = accumulate(begin(weights),end(weights),0);
        int minCap = *max_element(begin(weights),end(weights));
        int result = minCap;
        while(maxCap>=minCap)
        {
            int cap = minCap+(maxCap-minCap)/2;
            if(canTransport(weights,cap,days))
            {
                result=cap;
                maxCap=cap-1;
            }
            else minCap = cap+1;
        }
        return result;
    }
private:
    bool canTransport(vector<int>& weights, int cap, int days)
    {
        int temp = cap;
        for(int i=0;i<weights.size() && days>0;i++)
        {
            if(weights[i]<=temp) temp-=weights[i];
            else
            {
                days--;
                temp = cap-weights[i];
            }
        }
        return days>0;
    }
};