#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int res = INT_MAX;
        vector<int> sNum;
        vector<int> tNum;
        sNum.resize(26);
        tNum.resize(26);
        for(int i=0;i<s.size();i++)
        {
            sNum[s[i]-97]++;
        }
        for(int i=0;i<target.size();i++)
        {
            tNum[target[i]-97]++;
        }
        for(int i=0;i<26;i++)
        {
            if(tNum[i]!=0)
            {
                sNum[i]/=tNum[i];
                if(res>sNum[i]) res = sNum[i];
            }
        }
        return res;
    }
};