#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        map<int,vector<int>> add;
        map<int,vector<int>> sub;
        map<int,int> tot;
        map<int,vector<int>> query;
        int qsz = queries.size();
        vector<int> res(qsz);
        for(auto& interv : intervals)
        {
            add[interv[0]].push_back(interv[1]-interv[0]+1);
            sub[interv[1]].push_back(interv[1]-interv[0]+1);
        }
        for(int i=0;i<qsz;i++) query[queries[i]].push_back(i);
        auto ita = add.begin();
        auto its = sub.begin();
        auto itq = query.begin();
        int i = min(ita->first,itq->first);
        int ai = 0;
        int si = 0;
        int qi = 0;
        while(itq!=query.end())
        {
            if(add.count(i)>0)
            {
                for(auto& e : add[i]) tot[e]++;
                ita++;
            }
            if(query.count(i)>0)
            {
                for(auto& e : query[i])
                {
                    if(tot.size()>0) res[e]=tot.begin()->first;
                    else res[e]=-1;
                }
                itq++;
            }
            if(sub.count(i)>0)
            {
                for(auto& e : sub[i])
                {
                    tot[e]--;
                    if(tot[e]==0) tot.erase(e);
                }
                its++;
            }
            ai = (ita!=add.end())? ita->first : INT_MAX;
            si = (its!=sub.end())? its->first : INT_MAX;
            qi = (itq!=query.end())? itq->first : INT_MAX;
            i = min(ai,min(si,qi));
        }
        return res;
    }
};