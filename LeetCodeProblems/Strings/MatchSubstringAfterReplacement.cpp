#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int subS = sub.size();
        map<char,set<char>> m;
        for(int i=0;i<mappings.size();i++)
        {
            m[mappings[i][0]].insert(mappings[i][1]);
        }
        for(int i=0;i+subS<=s.size();i++)
        {
            bool correctSwap = true;
            for(int j=0;j<subS && correctSwap;j++)
            {
                if((sub[j]!=s[i+j]) && (m[sub[j]].find(s[i+j])==m[sub[j]].end())) correctSwap = false;
            }
            if(correctSwap) return true;
        }
        return false;
    }
};