#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();
        string result(sz1+sz2,0);
        for(int i=0;i<min(sz1,sz2);i++)
        {
            result[i*2] = word1[i];
            result[i*2+1] = word2[i];
        }
        for(int i=sz2;i<sz1;i++)
        {
            result[sz2+i]=word1[i];
        }
        for(int i=sz1;i<sz2;i++)
        {
            result[sz1+i]=word2[i];
        }
        return result;
    }
};