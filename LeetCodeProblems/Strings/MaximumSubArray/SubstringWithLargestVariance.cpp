#include <set>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int res = 0;
        set<int> letterPresent;
        for(auto k : s) letterPresent.insert(k);
        for(auto i : letterPresent)
        {
            for(auto j : letterPresent)
            {
                if(i==j) continue;
                int totF = 0;
                int totS = 0;
                for(int k=0;k<s.size();k++)
                {
                    if(s[k]==i) totF++;
                    if(s[k]==j) totS++;
                    if(totF-totS<0)
                    {
                        totF = 0;
                        totS = 0;
                    }
                    else res = max(res,totF-max(totS,1));
                }
                res = max(res,totF-max(totS,1));
            }
        }
        return res;
    }
};