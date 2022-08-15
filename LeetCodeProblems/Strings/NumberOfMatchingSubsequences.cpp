#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        changeSourceString(s);
        for(int i=0;i<words.size();i++)
        {
            int pos = 0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]==words[i][pos]) pos++;
                if(pos>=words[i].size()) 
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
private:
    void changeSourceString(string& s)
    {
        int pos = 0;
        for(int i=0;i<s.size();)
        {
            s[pos++]=s[i];
            int j=1;
            for(;j+i<s.size() && s[i+j]==s[i+j-1];j++)
            {
                if(j<50) s[pos++]=s[i+j];
            }
            i+=j;
        }
        s.resize(pos);
    }
};