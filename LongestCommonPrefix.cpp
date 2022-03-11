#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int calculateMinSize(vector<string>& strs) {
        int sz = 200;
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()<sz)
            {
                sz = strs[i].size();
            }
        }
        return sz;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        prefix.resize(200);
        bool different = false;
        int minSz = calculateMinSize(strs);
        int sz = 0;
        for(sz = 0; sz<minSz && different == false;)
        {
            for(int i=1;i<strs.size() && different == false;i++)
            {
                if(strs[i][sz]!=strs[0][sz])
                {
                    different = true;
                }
            }
            if(different == false)
            {
                prefix[sz] = strs[0][sz];
                sz++;
            }
        }
        prefix.resize(sz);
        return prefix;
    }
};

int main()
{
    Solution solution;
    return 0;
}