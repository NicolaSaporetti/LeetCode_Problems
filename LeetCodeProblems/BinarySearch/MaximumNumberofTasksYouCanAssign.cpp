#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        int minW = 0;
        int maxW = min(workers.size(),tasks.size());
        int result = minW;
        while(minW<=maxW)
        {
            int medW = minW+(maxW-minW)/2;
            if(workCap(medW,workers,tasks, pills, strength))
            {
                result = medW;
                minW = medW+1;
            }
            else maxW = medW-1;
        }
        return result;
    }
    
    bool workCap(int num, vector<int>& workers, vector<int>& tasks, int pills, int strength)
    {
        map<int,int> m;
        for(auto& w : workers) m[w]++;
        for(int i=num-1;i>=0;i--)
        {
            auto it = m.lower_bound(tasks[i]);
            if(it!=m.end())
            {
                m[it->first]--;
                if(m[it->first]==0) m.erase(it->first);
            }
            else
            {
                if(pills<=0) return false;
                pills--;
                it = m.lower_bound(tasks[i]-strength);
                if(it!=m.end())
                {
                    m[it->first]--;
                    if(m[it->first]==0) m.erase(it->first);
                }
                else return false;
            }
        }
        return true;
    }
};