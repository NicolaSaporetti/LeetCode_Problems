#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> g(n);
        vector<bool> in(n,false);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                g[i].push_back(leftChild[i]);
                in[leftChild[i]]=true;
            }
            if(rightChild[i]!=-1)
            {
                g[i].push_back(rightChild[i]);
                in[rightChild[i]]=true;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!in[i])
            {
                vector<bool> vis(n,false);
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int e = q.front();
                    q.pop();
                    cout<<e<<endl;
                    if(vis[e]) return false;
                    else vis[e]=true;
                    for(int i=0;i<g[e].size();i++) q.push(g[e][i]);
                }
                return all_of(begin(vis),end(vis),[](bool el){return el;});
            }
        }
        return false;
    }
};