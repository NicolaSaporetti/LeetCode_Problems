#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(double(coordinates[1][0]-coordinates[0][0])==0)
        {
            for(int i=2;i<coordinates.size();i++)
            {
                if(coordinates[i][0]!=coordinates[0][0]) return false;
            }
        }
        else
        {
            double m = double(coordinates[1][1]-coordinates[0][1])/double(coordinates[1][0]-coordinates[0][0]);
            for(int i=2;i<coordinates.size();i++)
            {
                double n = double(coordinates[i][1]-coordinates[0][1])/double(coordinates[i][0]-coordinates[0][0]);
                if(m!=n) return false;
            }
        }
        return true;
    }
};