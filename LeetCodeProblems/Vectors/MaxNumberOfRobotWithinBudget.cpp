#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        sz = chargeTimes.size();
        vector<long long> cum(sz+1,0);
        m[0]++;
        res = 0;
        for(int i=0;i<sz;i++) cum[i+1]=cum[i]+runningCosts[i];
        computeMaxActiveConsecutiveRobots(chargeTimes, cum, budget);
        return res;
    }
    
private:
    int computeMaxActiveConsecutiveRobots(vector<int>& chargeTimes, vector<long long>& cum, long long budget)
    {
        int wz = 0;
        for(int i=0;i<sz;i++)
        {
            wz++;
            m[chargeTimes[i]]++;
            auto it = m.rbegin();
            while((cum[i+1]-cum[i+1-wz])*wz+it->first>budget)
            {
                wz--;
                int val = chargeTimes[i-wz];
                m[val]--;
                if(m[val]==0) m.erase(val);
                it=m.rbegin();
            }
            res = max(res,wz);
        }
        return res;
    }
    
    int sz;
    int res;
    map<long long,int> m;
};