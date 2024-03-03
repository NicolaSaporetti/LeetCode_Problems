#include <vector>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int sz = bl.size();
        long long r = 0;
        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                long long trx = min(tr[i][0],tr[j][0]);
                long long tryy = min(tr[i][1],tr[j][1]);
                long long brx = max(bl[i][0],bl[j][0]);
                long long bry = max(bl[i][1],bl[j][1]);
                if(trx<=brx || tryy<=bry) continue;
                r = max(r,min(trx-brx,tryy-bry));
            }
        }
        return r*r;
    }
};