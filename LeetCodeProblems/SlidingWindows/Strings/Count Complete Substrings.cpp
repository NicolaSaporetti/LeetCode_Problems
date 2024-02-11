#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        res = 0;
        for(int i=0;i<word.size();i++)
        {
            if(i>0 && abs(word[i]-word[i-1])>2)
            {
                compute(word, k, i-1);
                m.clear();
            }
            m[word[i]-'a'].push_back(i);
        }
        compute(word, k, word.size()-1);
        return res;
    }
private:
    void compute(string& word, int k, int e)
    {
        for(auto& [ke,v] : m)
        {
            if(v.size()<k) continue;
            vector<int> f(26,0);
            int s = 0;
            for(int i=v[s];i<=e;i++)
            {
                f[word[i]-'a']++;
                if(f[ke]>k)
                {
                    for(int j=v[s];j<v[s+1];j++) f[word[j]-'a']--;
                    s++;
                }
                if(isOk(k,f)) res++;
            }
        }
    }
    
    bool isOk(int k, vector<int> & v)
    {
        for(int i=0;i<26;i++) if(v[i]>0 && v[i]!=k) return false;
        return true;
    }
    
    int res;
    map<int,vector<int>> m;
};