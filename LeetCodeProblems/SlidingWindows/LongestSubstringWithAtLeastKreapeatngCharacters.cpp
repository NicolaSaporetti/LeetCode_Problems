#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        sz=s.size();
        res = 0;
        computeLongest(s,k,0,sz);
        return res;
    }
    
private:
    void computeLongest(string& s, int k, int start, int end)
    {
        if(end-start+1<k) return;
        v.assign(26,0);
        for(int i=start;i<end;i++) v[s[i]-'a']++;
        vector<int> removedLetters;
        for(int i=0;i<26;i++)
        {
            if(v[i]!=0 && v[i]<k) removedLetters.push_back(i);
        }
        if(removedLetters.empty()) res = max(res, end-start);
        int temp_start = start;
        for(int i=start;i<end;i++)
        {
            if(isInvalid(s[i],removedLetters))
            {
                computeLongest(s,k,temp_start,i);
                temp_start = i+1;
            }
        }
        if(temp_start!=start) computeLongest(s,k,temp_start,end);
    }
    
    bool isInvalid(char c, vector<int>& removedLetters)
    {
        for(int i=0;i<removedLetters.size();i++)
        {
            if(c==removedLetters[i]+'a') return true;
        }
        return false;
    }
    
    int res;
    int sz;
    vector<int> v;
};