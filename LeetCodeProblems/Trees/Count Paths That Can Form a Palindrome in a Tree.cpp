#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        unordered_map<int,long long> m;
        int sz = parent.size();
        vector<int> mask(sz);
        long long res=0;
        vector<vector<int>> rootToLeaf(sz);
        for(int i=1;i<sz;i++) rootToLeaf[parent[i]].push_back(i);
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int el = q.front();
            for(auto e : rootToLeaf[el])
            {
                int newMask = mask[el];
                newMask^=(1<<(s[e]-'a'));
                mask[e]=newMask;
                q.push(e);
            }
            res+=m[mask[el]];
            for(int i=0;i<26;i++)
            {
                int newMask = mask[el];
                newMask^=(1<<i);
                res+=m[newMask];
            }
            q.pop();
            m[mask[el]]++;
        }
        return res;
    }
};