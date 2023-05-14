#include <vector>
using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int pos = 0;
        int res = 0;
        for(int i=0;i<rungs.size();i++)
        {
            if(rungs[i]-pos>dist)
            {
                int num = (rungs[i]-pos)/dist-1+(((rungs[i]-pos)%dist==0)? 0 : 1);
                res+=num;
            }
            pos = rungs[i];
        }
        return res;
    }
};