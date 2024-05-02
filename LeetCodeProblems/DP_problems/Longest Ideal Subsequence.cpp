#include <vector>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++)
        {
            int val = 0;
            for(int j=0;j<26;j++) if(abs(s[i]-'a'-j)<=k) val = max(v[j]+1,val);
            v[s[i]-'a']=val;
        }
        return *max_element(begin(v),end(v));
    }
};