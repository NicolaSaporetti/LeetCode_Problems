#include <vector>
#include <unordered_map>
#include "SimpleTrie.cpp"
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        n = 0;
        Trie* so = new Trie();
        Trie* ta = new Trie();
        for(int i=0;i<cost.size();i++)
        {
            if(m.count(original[i])==0) m[original[i]]={n++};
            if(m.count(changed[i])==0) m[changed[i]]={n++};
            int v1 = m[original[i]];
            int v2 = m[changed[i]];
            so->insert(original[i]);
            ta->insert(changed[i]);
        }
        g.assign(n,vector<int>(n,1e9));
        for(int i=0;i<cost.size();i++)
        {
            int v1 = m[original[i]];
            int v2 = m[changed[i]];
            g[v1][v2]=min(g[v1][v2],cost[i]);
        }
        FloydWarshall();
        vector<long long> dp(source.size()+1,-1);
        dp[source.size()]=0;
        
        for(int i=source.size()-1;i>=0;i--)
        {
            string ss;
            string rr;
            Trie* s = so;
            Trie* r = ta;
            if(source[i]==target[i]) dp[i]=dp[i+1];
            for(int j=i;j<source.size();j++)
            {
                ss+=source[j];
                rr+=target[j];
                s = s->ch[source[j]-'a'];
                r = r->ch[target[j]-'a'];
                if(s==nullptr || r ==nullptr) break;
                if(dp[j+1]!=-1 && s->endWord && r->endWord)
                {
                    int src = m[ss];
                    int tgt = m[rr];
                    if(g[src][tgt]<1e9)
                    {
                        long long c = g[src][tgt];
                        if(dp[i]==-1) dp[i]=dp[j+1]+c;
                        else dp[i] = min(dp[i],dp[j+1]+c);
                    }
                }
            }
        }
        return dp[0];
    }
private:
    void FloydWarshall()
    {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]); 
                }
            }
        }
    }

    vector<vector<int>> g;
    unordered_map<string,int> m;
    int n;
};