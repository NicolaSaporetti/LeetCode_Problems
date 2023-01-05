#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        int res = 0;
        for(auto t : tasks) m[t]++;
        for(auto it = m.begin();it!=m.end();it++)
        {
            if(it->second==1) return -1;
            else
            {
                res+=(it->second/3);
                it->second-=(it->second/3)*3;
                res+=(it->second!=0) ? 1 : 0;
            }
        }
        return res;
    }
};