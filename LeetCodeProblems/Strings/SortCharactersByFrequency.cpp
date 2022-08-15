#include <iostream>
#include <vector>
using namespace std;

bool myfunction (vector<int> i,vector<int> j) {
    return (i[1]>j[1]);
}

class Solution {
public:
    string frequencySort(string s) {
        vector<vector<int>> alph(75,vector<int>(2,0));
        int pos = 0;
        for(int i=0;i<75;i++)
        {
            alph[i][0]=i;
        }
        for(int i=0;i<s.size();i++)
        {
            alph[s[i]-'0'][1]++;
        }
        sort(alph.begin(),alph.end(),myfunction);
        for(int i=0;i<alph.size();i++)
        {
            for(int j=0;j<alph[i][1];j++)
            {
                s[pos++]=alph[i][0]+'0';
            }
        }
        return s;
    }
};