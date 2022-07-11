#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int sz;
    
    bool putBalls(vector<int>& position, int force, int balls) {
        balls--;
        int lastBallPos = position[0];
        for(int i=1;i<sz && balls>0;i++)
        {
            if(position[i]-force>=lastBallPos)
            {
                lastBallPos = position[i];
                balls--;
            }
        }
        return (balls==0)? true : false;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        sz = position.size();
        sort(position.begin(),position.end());
        int minF = 1;
        int maxF = (position[sz-1]-position[0])/(m-1);
        while(minF<maxF)
        {
            int force = (minF+maxF+1)/2;
            bool allBallUsed = putBalls(position,force,m);
            if(allBallUsed)
            {
                minF = force;
            }
            else
            {
                maxF= force-1;
            }
        }
        return minF;
    }
};