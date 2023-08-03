#include <set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        vector<bool> v(sz+1,false);
        v[0]=true;
        for(int i=0;i<=sz;i++)
        {
            if(v[i])
            {
                if(i==sz) return true;
                for(auto& w : wordDict)
                    if(w.size()+i<=sz && s.substr(i,w.size())==w) v[i+w.size()]=true;
            }
        }
        return false;
    }
};