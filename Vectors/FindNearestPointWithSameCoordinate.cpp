#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minM = INT_MAX;
        int index = -1;
        for(int i=0;i<points.size();i++)
        {
            if(points[i][0]==x && abs(points[i][1]-y)<minM)
            {
                index = i;
                minM = abs(points[i][1]-y);
            }
            if(points[i][1]==y && abs(points[i][0]-x)<minM)
            {
                index = i;
                minM = abs(points[i][0]-x);
            }
        }
        return index;
    }
};