#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        map<int,int> m;
        int res = 0;
        int maxR = 0;
        for(auto i : tiles)
        {
            if(i[0]<=i[1]) m[i[0]]=i[1];
            else m[i[1]]=i[0];
        }
        auto its = m.begin();
        int s = its->first;
        for(auto it = m.begin();it!=m.end();)
        {
            if(s+carpetLen-1>it->second)
            {
                res+=(it->second-it->first+1);
                it++;
            }
            else if(s+carpetLen-1<=it->second && s+carpetLen-1>=it->first)
            {
                res+=(s+carpetLen-1-it->first+1);
                maxR = max(maxR,res);
                if(maxR==carpetLen) return carpetLen;
                res-=(s+carpetLen-1-it->first+1);
                res-=(its->second-its->first+1);
                its++;
                s=its->first;
            }
            else
            {
                maxR = max(maxR,res);
                res-=(its->second-its->first+1);
                its++;
                s=its->first;
            }
        }
        return max(maxR,res);
    }
};