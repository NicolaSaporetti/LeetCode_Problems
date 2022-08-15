#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
private:
    set<int> dryDay;
    map<int,int> myS;
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> result (rains.size(), -1);
        for(int i=rains.size()-1;i>=0;i--)
        {
            if(rains[i]==0) dryDay.insert(i);
            else
            {
                if(myS.count(rains[i]))
                {
                    if(!dryDay.empty())
                    {
                        int time_full = myS[rains[i]];
                        auto it2 = dryDay.upper_bound(time_full);
                        if(it2!=dryDay.begin())
                        {
                            it2--;
                            result[*it2]=rains[i];
                            dryDay.erase(it2);
                            myS[rains[i]]= i;
                        }
                        else
                        {
                            return vector<int>{};
                        }
                    }
                    else
                    {
                        return vector<int>{};
                    }
                }
                else myS.insert(make_pair(rains[i],i));
            }
        }
        fillRemainingDryDays(result);
        return result;
    }
    
    void fillRemainingDryDays(vector<int>& result)
    {
        for(auto it=dryDay.begin();it!=dryDay.end();it++)
        {
            result[*it]=1;
        }
    }
};