#include <vector>
using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size()) return false;
        int rep = (k-1)/26;
        vector<int> v(26,rep);
        for(int i=0;i<26;i++)
        {
            if(k-rep*26>=i) v[i]++;
        }
        for(int i=0;i<s.size();i++)
        {
            int dif = (t[i]-s[i]+26)%26;
            if(dif>0)
            {
                if(v[dif]==0) return false;
                else v[dif]--;
            }
        }
        return true;
    }
};