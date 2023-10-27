#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<vector<string>> w(10);
        vector<vector<int>> g(10);
        for(int i=0;i<n;i++)
        {
            int sz = words[i].size();
            w[sz-1].push_back(words[i]);
            g[sz-1].push_back(groups[i]);
        }
        vector<string> res;
        vector<vector<string>> r;
        int d = 0;
        for(int i=0;i<10;i++)
        {
            if(w[i].size()>0) r.push_back(compute(w[i],g[i]));
        }
        for(auto& e : r) if(e.size()>res.size()) res = e;
        return res;        
    }
private:
    vector<string> compute(vector<string>& w, vector<int>& g)
    {
        vector<string> res;
        unordered_map<int,vector<int>> m;
        int sz = w.size();
        vector<int> p(sz,1);
        for(int i=sz-1;i>=0;i--)
        {
            for(auto& [k,v] : m)
            {
                for(auto& e : v)
                    if(g[i]!=k && dist(w[i],w[e])==1) p[i] = max(p[i],p[e]+1);
            }
            m[g[i]].push_back(i);
        }
        int cell = max_element(begin(p),end(p))-begin(p);
        res.push_back(w[cell]);
        for(int i=cell+1;i<sz;i++)
        {
            if(dist(w[cell],w[i])==1 && p[i]==p[cell]-1 && g[i]!=g[cell])
            {
                res.push_back(w[i]);
                cell = i;
            }
        }
        return res;
    }
    
    int dist(string& s1, string& s2)
    {
        int r =0;
        int sz1= s1.size();
        for(int i=0;i<sz1;i++)
        {
            if(s1[i]!=s2[i]) r++;
        }
        return r;
    }
};