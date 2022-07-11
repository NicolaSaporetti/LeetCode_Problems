#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    bool isStringInterleaved;
    vector<int> comb;
    set<vector<int>> myS;
    
    void areInterleaved(string& s1, string& s2, string& s3, int i1, int i2)
    {
        comb[0]=i1;
        comb[1]=i2;
        auto it = myS.find(comb);
        if(!isStringInterleaved && it==myS.end())
        {
            myS.insert(comb);
            if(i1+i2==s3.size()) isStringInterleaved = true;
            if(i2<s2.size() && s3[i1+i2]==s2[i2])
            {
                areInterleaved(s1,s2,s3,i1,i2+1);
            }
            if(i1<s1.size() && s3[i1+i2]==s1[i1])
            {
                areInterleaved(s1,s2,s3,i1+1,i2);
            }
        }
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        isStringInterleaved = false;
        comb.resize(2);
        areInterleaved(s1,s2,s3,0,0);
        return isStringInterleaved;
    }
};