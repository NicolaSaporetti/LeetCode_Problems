#include <vector>
#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int sz = amount.size();
        ma=buildDirectGraphToLeafs(edges,sz);
        mb=buildDirectGraphToRoot(ma,sz);
        r = INT_MIN;
        traverse(0,bob,amount,0);
        return r;
    }
    
private:
    vector<vector<int>> buildDirectGraphToLeafs(vector<vector<int>>& edges, int sz)
    {
        vector<set<int>> m(sz);
        vector<vector<int>> res(sz);
        for(auto e : edges)
        {
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            for(auto e : m[el])
            {
                m[e].erase(el);
                q.push(e);
            }
        }
        for(int i=0;i<sz;i++)
            for(auto e : m[i]) res[i].push_back(e);
        return res;
    }
    vector<int> buildDirectGraphToRoot(vector<vector<int>>& graphRootToLeaf, int sz)
    {
        vector<int> res(sz);
        for(int i=0;i<sz;i++)
            for(int j=0;j<graphRootToLeaf[i].size();j++) res[graphRootToLeaf[i][j]]=i;
        return res;
    }
    
    void traverse(int alice, int bob, vector<int>& amount, int reward)
    {
        reward += (alice==bob)? amount[alice]/2 : amount[alice];
        if(ma[alice].size()==0)
        {
            r = max(r,reward);
            return;
        }
        else
        {
            int temp = amount[bob];
            amount[bob]=0;
            for(int i=0;i<ma[alice].size();i++)
            {
                traverse(ma[alice][i],mb[bob],amount,reward);
            }
            amount[bob]=temp;
        }
    }
    
    vector<vector<int>> ma;
    vector<int> mb;
    int r;
};