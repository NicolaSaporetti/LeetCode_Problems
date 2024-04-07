#include <vector>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sz = possible.size();
        vector<int> v(sz+1);
        for(int i=0;i<sz;i++)
        {
            v[i+1]=v[i]+((possible[i]==0)? -1 : 1);
        }
        for(int i=1;i<sz;i++) if(v[i]>v[sz]-v[i]) return i;
        return -1;
    }
};