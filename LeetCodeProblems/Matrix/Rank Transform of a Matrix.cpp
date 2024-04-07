#include <vector>
#include <unordered_map>
#include <queue>
#include "DisjoinSetUnion.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        rz = matrix.size();
        cz = matrix[0].size();
        vector<int> v1 = computeUniqueSets(matrix);
        for(auto e : v1) in[e]=0;
        computeGraphs(matrix, v1);
        
        queue<int> q;
        vector<vector<int>> res(rz,vector<int>(cz,0));
        for(auto& [k,v] :in) if(v==0) q.push(k);
        int dif = 1;
        unordered_map<int,int> res1;
        while(!q.empty())
        {
            int n= q.size();
            for(int k=0;k<n;k++)
            {
                int el = q.front();
                res1[el]=dif;
                q.pop();
                for(int i=0;i<m[el].size();i++)
                {
                    int nel = m[el][i];
                    in[nel]--;
                    if(in[nel]==0) q.push(nel);
                }
            }
            dif++;
        }
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) res[i][j]= res1[v1[i*cz+j]];
        return res;
    }
private:
    vector<int> computeUniqueSets(vector<vector<int>>& matrix)
    {
        DisjoinSetUnion ds(rz*cz);
        vector<int> res;
        for(int i=0;i<rz;i++)
        {
            vector<pair<int,int>> r;
            for(int j=0;j<cz;j++) r.push_back({matrix[i][j],j});
            sort(begin(r),end(r));
            for(int j=1;j<cz;j++)
                if(r[j].first==r[j-1].first) ds.connect(i*cz+r[j-1].second,i*cz+r[j].second);
        }
        for(int i=0;i<cz;i++)
        {
            vector<pair<int,int>> c;
            for(int j=0;j<rz;j++) c.push_back({matrix[j][i],j});
            sort(begin(c),end(c));
            for(int j=1;j<rz;j++)
                if(c[j].first==c[j-1].first) ds.connect(c[j-1].second*cz+i,c[j].second*cz+i);
        }
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) res.push_back(ds.find_set(i*cz+j));
        return res;
    }
    void computeGraphs(vector<vector<int>>& matrix, vector<int>& v1)
    {
        for(int i=0;i<rz;i++)
        {
            vector<pair<int,int>> r;
            for(int j=0;j<cz;j++) r.push_back({matrix[i][j],v1[i*cz+j]});
            sort(begin(r),end(r));
            for(int j=1;j<cz;j++)
            {
                if(r[j].first>r[j-1].first)
                {
                    m[r[j-1].second].push_back(r[j].second);
                    in[r[j].second]++;
                }
            }
        }
        for(int i=0;i<cz;i++)
        {
            vector<pair<int,int>> c;
            for(int j=0;j<rz;j++) c.push_back({matrix[j][i],v1[j*cz+i]});
            sort(begin(c),end(c));
            for(int j=1;j<rz;j++)
            {
                if(c[j].first>c[j-1].first)
                {
                    m[c[j-1].second].push_back(c[j].second);
                    in[c[j].second]++;
                }
            }
        }
    }
    
    int rz;
    int cz;
    unordered_map<int,vector<int>> m;
    unordered_map<int,int> in;
};