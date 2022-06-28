#include <iostream>
using namespace std;

class Solution {
private:
    
public:
    int firstUniqChar(string s) {
        int firstUnique = INT_MAX;
        vector<int> starting(26,-1);
        vector<bool> duplicate(26,false);
        int sz = s.size();
        
        for(int i=0;i<sz;i++)
        {
            if(starting[s[i]-'a']!=-1) duplicate[s[i]-'a'] = true;
            starting[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++)
        {
            if(!duplicate[i] && starting[i]!=-1) firstUnique = min(firstUnique,starting[i]);
        }
        if(firstUnique!=INT_MAX) return firstUnique;
        else return -1;
    }
};