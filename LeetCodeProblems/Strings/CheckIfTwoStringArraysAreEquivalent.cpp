#include <iostream>include <vector>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int k=0,y=0,i=0,j=0;
        for(;i<word1.size() && j<word2.size();)
        {
            for(;k<word1[i].size() && y<word2[j].size();)
            {
                if(word1[i][k++]!=word2[j][y++]) return false;
            }
            if(k>=word1[i].size())
            {
                k=0;
                i++;
            }
            if(y>=word2[j].size())
            {
                y=0;
                j++;
            }
        }
        if(i==word1.size() && j==word2.size()) return true;
        else return false;
    }
};