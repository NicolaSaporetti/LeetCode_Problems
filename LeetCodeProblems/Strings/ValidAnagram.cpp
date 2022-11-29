#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> comp(26,0);
        int sz = s.size();
        
        for(int i=0;i<sz;i++)
        {
            comp[s[i]-'a']++;
            comp[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(comp[i]) return false;
        }
        return true;
        
    }
};