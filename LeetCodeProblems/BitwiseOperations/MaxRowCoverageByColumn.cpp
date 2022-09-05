#include <vector>
using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int rz = mat.size();
        int cz = mat[0].size();
        int masks = pow(2,cz);
        int maxCove = 0;
        for(int i=0;i<=masks;i++)
        {
            int temp = 0;
            for(int j=0;j<cz;j++) if((1<<j)&i) temp++;
            if(temp==cols)
            {
                int tot = 0;
                for(int j=0;j<rz;j++)
                {
                    bool exit = false;
                    for(int k=0;k<cz && !exit;k++)
                    {
                        int val = (1<<k)&i;
                        if(val==0 && mat[j][k]==1) exit = true; 
                    }
                    if(!exit) tot++;
                }
                maxCove = max(maxCove, tot);
            }
        }
        return maxCove;
    }
};