#include <vector>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        vector<int> dif;
        vector<bool> rep(26,false);
        bool duplicateLetter = false;
        int sz = s.size();
        for(int i=0;i<sz;i++)
        {
            if(s[i]!=goal[i]) dif.push_back(i);
            if(rep[s[i]-'a']) duplicateLetter = true;
            rep[s[i]-'a'] = true;
        }
        if((dif.size()==0 && duplicateLetter) || (dif.size()==2 && s[dif[0]]==goal[dif[1]] && s[dif[1]]==goal[dif[0]])) return true;
        else return false;
    }
};