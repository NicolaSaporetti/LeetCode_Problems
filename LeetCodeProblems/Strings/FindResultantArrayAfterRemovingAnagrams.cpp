#include <vector>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int s = 0;
        for(int i=1;i<words.size();i++)
        {
            vector<int> a(26,0);
            bool match = true;
            if(words[s].size()==words[i].size())
            {
                for(int j=0;j<words[i].size();j++)
                {
                    a[words[s][j]-'a']++;
                    a[words[i][j]-'a']--;
                }
                for(int j=0;j<26 && match;j++)
                {
                    if(a[j]!=0) match = false;
                }
            }
            else match = false;
            if(!match)
            {
                words[++s] = words[i];
            }
        }
        words.resize(s+1);
        return words;
    }
};