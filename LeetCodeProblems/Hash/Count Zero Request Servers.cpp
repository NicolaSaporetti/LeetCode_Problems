#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        map<int,int> add = computeAvailableServers(logs,x);
        map<int,vector<int>> q;
        vector<int> res(queries.size(),n);
        for(int i=0;i<queries.size();i++) q[queries[i]].push_back(i);
        int val = 0;
        auto it = q.begin();
        for(auto & [key,valor] : add)
        {
            while(it!=q.end() && it->first<key)
            {
                for(auto& e : it->second) res[e]=n-val;
                it++;
            }
            if(it==q.end()) break;
            val+=valor;
        }
        return res;
    }
private:
    map<int,int> computeAvailableServers(vector<vector<int>>& logs, int x)
    {
        map<int,vector<int>> m;
        map<int,int> add;
        for(auto & l : logs) m[l[0]].push_back(l[1]);
        for(auto& v : m)
        {
            sort(begin(v.second),end(v.second));
            int s = v.second[0];
            int e = s+x;
            add[s]++;
            for(int i=1;i<v.second.size();i++)
            {
                int ns = v.second[i];
                int ne = ns+x;
                if(ns>e)
                {
                    add[e+1]--;
                    add[ns]++;
                }
                e = ne;
            }
            add[e+1]--;
        }
        return add;
    }
};