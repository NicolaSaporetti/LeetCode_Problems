#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int sz = costs.size();
        map<int,set<int>> fs;
        map<int,set<int>> ss;
        long long tot = 0;
        for(int i=0;i<candidates;i++) fs[costs[i]].insert(i);
        for(int i=0;i<candidates;i++) ss[costs[sz-1-i]].insert(sz-1-i);
        int lowIndex = candidates;
        int highIndex = sz-candidates-1;
        for(int i=0;i<k;i++)
        {
            pair<int,int> elF = {fs.begin()->first,*fs.begin()->second.begin()};
            pair<int,int> elS = {ss.begin()->first,*ss.begin()->second.begin()};
            bool first_chosen = false;
            bool second_chosen = false;
            if(elF.first<elS.first || (elF.first==elS.first && elF.second<=elS.second)) first_chosen = true;
            if(elF.first>elS.first || (elF.first==elS.first && elF.second>=elS.second)) second_chosen = true;
            if(first_chosen) tot+=(long long)elF.first;
            else tot+=(long long)elS.first;
            if(first_chosen)
            {
                fs[elF.first].erase(elF.second);
                if(!fs[elF.first].size()) fs.erase(elF.first);
                costs[elF.second]=-1;
                while(lowIndex<sz && costs[lowIndex]==-1) lowIndex++;
                if(lowIndex<sz)
                {
                    fs[costs[lowIndex]].insert(lowIndex);
                    lowIndex++;
                }
            }
            if(second_chosen)
            {
                ss[elS.first].erase(elS.second);
                if(!ss[elS.first].size()) ss.erase(elS.first);
                costs[elS.second]=-1;
                while(highIndex>=0 && costs[highIndex]==-1) highIndex--;
                if(highIndex>=0)
                {
                    ss[costs[highIndex]].insert(highIndex);
                    highIndex--;
                }
            }
        }
        return tot;
    }
};