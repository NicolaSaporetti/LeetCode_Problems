#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> graph(n);
        map<int, vector<int>> m1;
        for (int i = 0; i < n; ++i) 
        {
            m1[vals[i]].push_back(i);
        }
        for (auto& e : edges) 
        {
            int a = e[0];
            int b = e[1];
         
            if (vals[a] >= vals[b]) {
                graph[a].push_back(b);
            }
            if (vals[a] <= vals[b]) {
                graph[b].push_back(a);
            }
        }
        
        DisjoinSet d(n);
        int ans = 0;
        for (auto element : m1) 
        {
            int value = element.first;
            
            for (auto node : element.second) 
            {
                for (auto nbr : graph[node]) 
                {
                    d.connect(node, nbr);
                }
            }
           
            unordered_map<int, int> m2;
            for (auto node : element.second) 
            {
                m2[d.find_root(node)]++;
            }
            
            for (auto it=m2.begin();it!=m2.end();it++) 
            {
                if (it->second > 1) ans += (it->second * (it->second - 1)) / 2;
            }
        }
        return ans+n;
    }
};