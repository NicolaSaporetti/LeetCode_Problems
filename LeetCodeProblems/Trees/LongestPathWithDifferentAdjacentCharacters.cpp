#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        res = 0;
        v.resize(parent.size());
        for(int i=0;i<parent.size();i++) if(parent[i]!=-1) v[parent[i]].push_back(i);
        traverse(0,s);
        return res;
    }

private:
    int traverse(int node, string& s)
    {
        int ret = 1;
        int sum = 1;
        vector<int> vals;
        for(int i=0;i<v[node].size();i++)
        {
            int val = traverse(v[node][i],s);
            if(s[v[node][i]]!=s[node]) vals.push_back(val);
        }
        sort(vals.begin(),vals.end(),greater<int>());
        if(vals.size()>=2) sum+=vals[1];
        if(vals.size()>=1)
        {
            sum+=vals[0];
            ret+=vals[0];
        }
        res = max(res, sum);
        return ret;
    }
    
    int res;
    vector<vector<int>> v;
};