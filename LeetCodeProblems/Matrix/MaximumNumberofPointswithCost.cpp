#include <vector>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rz = points.size();
        int cz = points[0].size();
        vector<vector<long long>> p(rz,vector<long long>(cz,0));
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) p[i][j]=points[i][j];
        long long res = 0;
        for(int i=1;i<rz;i++)
        {
            for(int j=1;j<cz;j++) p[i-1][j]=max(p[i-1][j],p[i-1][j-1]-1);
            for(int j=cz-2;j>=0;j--) p[i-1][j]=max(p[i-1][j],p[i-1][j+1]-1);
            for(int j=0;j<cz;j++)
            {
                p[i][j]+=p[i-1][j];
            }
        }
        return *max_element(p[rz-1].begin(),p[rz-1].end());
    }
};