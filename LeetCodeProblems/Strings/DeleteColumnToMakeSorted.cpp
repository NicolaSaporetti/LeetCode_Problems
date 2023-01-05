#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rz = strs[0].size();
        int cz = strs.size();
        int tot = 0;
        for(int i=0;i<rz;i++)
        {
            for(int j=1;j<cz;j++)
            {
                if(strs[j][i]<strs[j-1][i])
                {
                    tot++;
                    break;
                }
            }
        }
        return tot;
    }
};