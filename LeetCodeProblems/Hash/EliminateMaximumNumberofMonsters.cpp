#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        map<int,int> m;
        for(int i=0;i<dist.size();i++)
        {
            m[dist[i]/speed[i]+((dist[i]%speed[i]==0) ? 0 : 1)]++;
        }
        auto it = m.begin();
        int val = 0;
        for(int i=0;i<dist.size();i++)
        {
            while(it!=m.end() && it->first<=i+1)
            {
                val+=it->second;
                it++;
            }
            if(val>i+1) return i+1;
        }
        return dist.size();
    }
};