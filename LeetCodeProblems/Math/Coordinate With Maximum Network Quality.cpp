#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxSignal = -1;
        int x = 0;
        int y = 0;
        for(int i=0;i<=50;i++)
            for(int j=0;j<=50;j++)
            {
                int signal = 0;
                for(int k=0;k<towers.size();k++)
                {
                    double dist = sqrt((double)(pow(towers[k][0]-i,2)+pow(towers[k][1]-j,2)));
                    if(dist<=(double)radius) signal += (int)((double)towers[k][2]/(1.0+dist));
                }
                if(signal>maxSignal)
                {
                    maxSignal = signal;
                    x = i;
                    y = j;
                }
            }
        return {x,y};
    }
};