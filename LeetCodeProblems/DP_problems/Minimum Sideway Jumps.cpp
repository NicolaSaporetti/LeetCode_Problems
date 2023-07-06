#include <vector>
using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> j(3,0);
        int n = obstacles.size();
        j[0]=1;
        j[2]=1;
        for(int i=1;i<n-1;i++)
        {
            if(obstacles[i]==0)
            {
                j[0]=min(j[0],1+min(j[1],j[2]));
                j[1]=min(j[1],1+min(j[0],j[2]));
                j[2]=min(j[2],1+min(j[1],j[0]));
            }
            else if(obstacles[i]==1)
            {
                j[0]=n;
                j[1]=min(j[1],1+j[2]);
                j[2]=min(j[2],1+j[1]);
            }
            else if(obstacles[i]==2)
            {
                j[1]=n;
                j[0]=min(j[0],1+j[2]);
                j[2]=min(j[2],1+j[0]);
            }
            else
            {
                j[2]=n;
                j[0]=min(j[0],1+j[1]);
                j[1]=min(j[1],1+j[0]);
            }
            
        }
        return min(j[0],min(j[1],j[2]));
    }
};