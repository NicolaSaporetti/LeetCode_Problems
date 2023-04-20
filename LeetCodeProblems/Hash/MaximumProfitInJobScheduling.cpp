#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int,vector<int>> m;
        map<int,int> maxP;
        maxP[0]=0;
        for(int i=0;i<startTime.size();i++) m[startTime[i]].push_back(i);
        for(auto& e : m)
        {
            for(auto p : e.second)
            {
                int start = e.first;
                int end = endTime[p];
                auto it = prev(maxP.upper_bound(start));
                int totalP = it->second+profit[p];
                bool isOk = true;
                while(it!=maxP.end() && it->first<=end && isOk)
                {
                    if(it->second>=totalP) isOk = false;
                    it++;
                }
                if(isOk)
                {
                    maxP[end]=totalP;
                    while(it!=maxP.end())
                    {
                        if(it->second<=totalP) it=maxP.erase(it);
                        else it++;
                    }
                }
            }
        }
        return maxP.rbegin()->second;
    }
};