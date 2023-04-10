#include <vector>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0;
        int sz = s.size();
        int z = count_if(begin(s),end(s),[](char el){return el=='0';});
        int o = sz-z;
        int start = 0, end = sz-1;
        while(start<=end)
        {
            while(start<sz && s[start]=='0')
            {
                start++;
                z--;
            }
            while(end>=0 && s[end]=='1')
            {
                end--;
                o--;
            }
            if(start>end) break;
            if(z>=o)
            {
                start++;
                o--;
            }
            else
            {
                end--;
                z--;
            }
            res++;
        }
        return res;
    }
};