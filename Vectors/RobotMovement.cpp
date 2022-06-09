#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int result =0;
        if(startPos[0]>homePos[0])
        {
            for(int i=1;i<=startPos[0]-homePos[0];i++)
            {
                result +=rowCosts[startPos[0]-i];
            }
        }
        else if(startPos[0]<homePos[0])
        {
            for(int i=1;i<=homePos[0]-startPos[0];i++)
            {
                result +=rowCosts[startPos[0]+i];
            }
        }
        if(startPos[1]>homePos[1])
        {
            for(int i=1;i<=startPos[1]-homePos[1];i++)
            {
                result +=colCosts[startPos[1]-i];
            }
        }
        else if(startPos[1]<homePos[1])
        {
            for(int i=1;i<=homePos[1]-startPos[1];i++)
            {
                result +=colCosts[startPos[1]+i];
            }
        }
        return result;
    }
};