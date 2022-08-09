#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> codex(256,-1);
        vector<bool> used(256,false);
        for(int i=0;i<s.size();i++)
        {
            if(codex[s[i]]==-1)
            {
                if(!used[t[i]])
                {
                    codex[s[i]] = t[i];
                    used[t[i]] = true;
                }
                else return false;
            }
            else if(codex[s[i]]!=t[i]) return false;
        }
        return true;
    }
};