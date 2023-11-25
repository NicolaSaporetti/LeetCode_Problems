#include <vector>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int sz = s.size();
        int pos = 0;
        long long res = 0;
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='0')
            {
                res+=(long long)(i-pos);
                pos++;
            }
        }
        return res;
    }
};