#include <vector>
using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int sz = nextVisit.size();
        int mod = 1e9+7;
        vector<int> v(sz+1,0);
        v[1]=1;
        for(int i=1;i<sz;i++)
        {
            v[i+1]=v[i]*2+1;
            v[i+1] +=(nextVisit[i-1]==0)? 0 : -v[nextVisit[i-1]+1]+1;
            v[i+1]=(v[i+1]%mod+mod)%mod;
        }
        return ((v[sz]-1)%mod+mod)%mod;
    }
};