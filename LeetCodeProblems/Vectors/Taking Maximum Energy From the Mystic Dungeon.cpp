#include <vector>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int r = INT_MIN;
        int sz = energy.size();
        for(int i=0;i<k;i++)
        {
            int e = 0;
            for(int j=0;sz-1-i-j*k>=0;j++)
            {
                e+=energy[sz-1-i-j*k];
                r = max(r,e);
            }
        }
        return r;
    }
};