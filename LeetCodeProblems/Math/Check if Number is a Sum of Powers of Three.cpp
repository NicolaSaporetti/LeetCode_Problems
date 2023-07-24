#include <vector>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> v(20,1);
        vector<bool> vis(20,false);
        for(int i=1;i<20;i++) v[i]=v[i-1]*3;
        while(n>0)
        {
            int i=19;
            for(;i>=0;i--)
            {
                if(vis[i]) continue;
                else if(v[i]<=n)
                {
                    vis[i]=true;
                    n-=v[i];
                    break;
                }
            }
            if(i<0) return false;
        }
        return true;
    }
};