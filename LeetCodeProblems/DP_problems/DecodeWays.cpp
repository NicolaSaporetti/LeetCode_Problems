#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size()+1;
        vector<int> comb(sz,0);
        comb[0]=1;
        for(int i=0;i<sz-1;i++)
        {
            if(s[i]!='0')
            {
                comb[i+1]=comb[i];
            }
            if(i>0 && (s[i-1]-'0'==1 || (s[i-1]-'0'==2 && s[i]-'0'<7)))
            {
                comb[i+1]+=comb[i-1];
            }
        }
        return comb[sz-1];
    }
};