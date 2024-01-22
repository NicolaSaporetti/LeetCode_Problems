#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0;
        int rz = matrix.size();
        int cz = matrix[0].size();
        for(int i=1;i<rz;i++)
            for(int j=0;j<cz;j++)
                if(matrix[i][j]==1) matrix[i][j]+=matrix[i-1][j];
        vector<map<int,int>> v(rz);
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) v[i][matrix[i][j]]++;
        for(int i=0;i<rz;i++)
        {
            int prev = 0;
            for(auto it=v[i].rbegin();it!=v[i].rend();it++)
            {
                prev+=it->second;
                res =max(res,it->first*prev);
            }
        }
        return res;
    }
};