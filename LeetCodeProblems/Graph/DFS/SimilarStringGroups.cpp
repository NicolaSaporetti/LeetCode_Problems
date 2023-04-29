#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        nw=strs.size();
        computeGraph(strs);
        return computeGroups();
    }
private:
    void computeGraph(vector<string>& strs)
    {
        int wz=strs[0].size();
        m.resize(nw);
        for(int i=0;i<nw;i++)
        {
            for(int j=i+1;j<nw;j++)
            {
                int dif = 0;
                for(int z=0;z<wz && dif<3;z++)
                {
                    if(strs[i][z]!=strs[j][z]) dif++;
                }
                if(dif==2 || dif==0)
                {
                    m[i].push_back(j);
                    m[j].push_back(i);
                }
            }
        }
    }

    int computeGroups()
    {
        int res =0;
        vector<bool> vis(nw,false);
        for(int i=0;i<nw;i++)
        {
            if(!vis[i])
            {
                res++;
                queue<int> q;
                vis[i]=true;
                q.push(i);
                while(!q.empty())
                {
                    int el = q.front();
                    q.pop();
                    for(int j=0;j<m[el].size();j++)
                    {
                        int nel=m[el][j];
                        if(!vis[nel])
                        {
                            vis[nel]=true;
                            q.push(nel);
                        }
                    }
                }
            }
        }
        return res;
    }

    vector<vector<int>> m;
    int nw;
};