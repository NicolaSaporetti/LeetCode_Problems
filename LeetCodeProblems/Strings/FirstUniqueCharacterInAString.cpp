#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int pos = INT_MAX;
        vector<int> starting(26,-1);
        int sz = s.size();
        
        for(int i=0;i<sz;i++)
        {
            if(starting[s[i]-'a']==-1) starting[s[i]-'a']=i;
            else starting[s[i]-'a']=-2;
        }
        for(int i=0;i<26;i++)
        {
            if(starting[i]<pos && starting[i]>=0) pos = starting[i];
        }
        return (pos!=INT_MAX)? pos : -1;
    }
};