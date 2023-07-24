#include <vector>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1;
        int dist = INT_MAX;
        for(int i=0;i<points.size();i++)
            if(points[i][0]==x || points[i][1]==y)
            {
                int newD = pow((x-points[i][0]),2)+pow((y-points[i][1]),2);
                if(newD<dist)
                {
                    dist = newD;
                    res = i;
                }
            }
        return res;
    }
};