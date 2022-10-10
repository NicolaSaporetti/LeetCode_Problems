#include <vector>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> m(26,0);
        for(auto i : word)
        {
            m[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            m[i]--;
            int v = -1;
            bool found = true;
            for(int i=0;i<26 && found;i++)
            {
                if(m[i]!=0)
                {
                    if(v==-1) v = m[i];
                    else if(m[i]!=v)
                    {
                        found = false;
                    }
                }
            }
            if(found) return true;
            m[i]++;
        }
        return false;
    }
};