#include <vector>
using namespace std;

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int rz = destination[0]+1;
        int cz = destination[1]+1;
        vector<vector<int>> v(rz+1,vector<int>(cz+1,0));
        v[rz][cz-1]=1;
        string res;
        for(int i=rz-1;i>=0;i--)
        {
            for(int j=cz-1;j>=0;j--) v[i][j]=v[i+1][j]+v[i][j+1];
        }
        v[rz][cz-1]=0;
        int X = 0;
        int Y = 0;
        while(X!=rz-1 || Y!=cz-1)
        {
            if(k<=v[X][Y+1])
            {
                res.push_back('H');
                Y++;
            }
            else
            {
                res.push_back('V');
                k-=v[X][Y+1];
                X++;
            }
        }
        
        return res;
    }
};