#include <vector>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> d(days.back()+30,INT_MAX);
        d[0]=0;
        int el = 0;
        int i = 1;
        for(;i<366 && el<days.size();i++)
        {
            if(i!=days[el]) d[i]=min(d[i],d[i-1]);
            else
            {
                d[i]=min(d[i],d[i-1]+costs[0]);
                d[i+6]=min(d[i+6],d[i-1]+costs[1]);
                d[i+29]=min(d[i+29],d[i-1]+costs[2]);
                el++;
            }
        }
        int res = d[days.back()];
        for(;i<days.back()+30;i++) res = min(res, d[i]);
        return res;
    }
};