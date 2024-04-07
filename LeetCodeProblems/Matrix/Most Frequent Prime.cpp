#include <vector>
using namespace std;

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int rz = mat.size();
        int cz = mat[0].size();
        vector<int> dx={-1,-1,-1,0,1,1,1,0};
        vector<int> dy={-1,0,1,1,1,0,-1,-1};
        map<int,int> f;
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                for(int y=0;y<8;y++)
                {
                    int v = 0;
                    for(int z=0;z<6;z++)
                    {
                        int nx=i+dx[y]*z;
                        int ny=j+dy[y]*z;
                        if(nx<0 || nx>=rz || ny<0 || ny>=cz) break;
                        v*=10;
                        v+=mat[nx][ny];
                        f[v]++;
                    }
                }
            }
        }
        int res = -1;
        map<int,set<int>> m;
        for(auto [k,v] : f) if(k>10 && MillerRabin(k)) m[v].insert(k);
        if(m.empty()) return -1;
        else
        {
            return *m.rbegin()->second.rbegin();
        }
    }
};