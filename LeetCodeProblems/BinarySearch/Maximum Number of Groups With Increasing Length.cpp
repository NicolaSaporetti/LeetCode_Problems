#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        int res = 1;
        sort(usageLimits.begin(),usageLimits.end());
        int maxE = usageLimits.size();
        int minE = 1;
        while(minE<=maxE)
        {
            int avg = minE+(maxE-minE)/2;
            if(compute(usageLimits,avg))
            {
                res = avg;
                minE = avg+1;
            }
            else maxE = avg-1;
        }
        return res;
        
    }
private:
    bool compute(vector<int>& u, long long lim)
    {
        int n = lim;
        long long left = 0;
        for(int i=u.size()-1;i>=0 && lim>0;i--,lim--)
        {
            long long el = min((long long)u[i],lim);
            left+=(lim-el);
            int rem = (u[i]-lim);
            if(rem>0) left-=rem;
            if(left<0) left = 0;
        }
        for(int i=0;i<u.size()-n;i++) left-=u[i];
        return (left<=0);
    }
};