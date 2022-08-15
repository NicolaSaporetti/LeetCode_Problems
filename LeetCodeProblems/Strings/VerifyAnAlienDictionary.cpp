#include <iostream>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=1;i<words.size();i++)
        {
            int j=0;
            for(;j<min(words[i].size(),words[i-1].size());j++)
            {
                int i1=find(order.begin(),order.end(),words[i-1][j])-order.begin();
                int i2=find(order.begin(),order.end(),words[i][j])-order.begin();
                if(i1<i2) break;
                if(i1>i2) return false;
            }
            if(j==min(words[i].size(),words[i-1].size()) && words[i].size()<words[i-1].size()) return false;
        }
        return true;
    }
};