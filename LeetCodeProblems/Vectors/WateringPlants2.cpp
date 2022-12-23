#include <vector>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int sz = plants.size();
        int r = 0;
        int vA = capacityA;
        int vB = capacityB;
        for(int i=0;i<sz/2;i++)
        {
            r += waterPlant(plants[i],capacityA,vA);
            r += waterPlant(plants[sz-1-i],capacityB,vB);
            vA-=plants[i];
            vB-=plants[sz-1-i];
        }
        if(sz%2==1)
        {
            if(vA<plants[sz/2] && vB<plants[sz/2]) r++;
        }
        return r;
    }
private:
    int waterPlant(int plant, int capacity, int& currentCapacity)
    {
        int recharge = 0;
        if(currentCapacity<plant)
        {
            currentCapacity=capacity;
            recharge++;
        }
        return recharge;
    }
};