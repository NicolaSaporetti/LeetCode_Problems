#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz;
        for(sz = 0; sz<strs[0].size();sz++)
        {
            for(int i=1;i<strs.size();i++)
            {
                if(strs[i].size()<sz || strs[i][sz]!=strs[0][sz])
                {
                    return strs[0].substr(0,sz);
                }
            }
        }
        return strs[0].substr(0,sz);
    }
};