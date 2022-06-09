#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> result;
    void verify(vector<int>& total, int index)
    {
        for(int i=0;i<total.size();i++)
        {
            if(total[i]!=0) return;
        }
        result.push_back(index);
    }
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return result;
        vector<int> total (26, 0);
        for(int i=0;i<p.size();i++)
        {
            total[p[i]-'a']--;
        }
        for(int i=0;i<p.size();i++)
        {
            total[s[i]-'a']++;
        }
        verify(total, 0);
        for(int i=p.size();i<s.size();i++)
        {
            total[s[i]-'a']++;
            total[s[i-p.size()]-'a']--;
            verify(total, i-p.size()+1);
        }
        return result;
    }
};