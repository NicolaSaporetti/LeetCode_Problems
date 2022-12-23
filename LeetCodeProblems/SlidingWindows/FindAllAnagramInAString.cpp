#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_sz=s.size();
        int p_sz=p.size();
        total.assign(26, 0);
        for(int i=0;i<p_sz;i++) total[p[i]-'a']--;
        for(int i=0;i<s_sz;i++)
        {
            total[s[i]-'a']++;
            if(i-p_sz>=0) total[s[i-p_sz]-'a']--;
            verify(i-p.size()+1);
        }
        return result;
    }
private:
    void verify(int index)
    {
        for(int i=0;i<26;i++)
        {
            if(total[i]!=0) return;
        }
        result.push_back(index);
    }
    vector<int> result;
    vector<int> total;
};