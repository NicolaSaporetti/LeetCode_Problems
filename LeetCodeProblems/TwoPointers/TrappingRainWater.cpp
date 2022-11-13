#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        waterTrapped=0;
        int lastMax=computeWaterInAscendingSection(height);
        computeWaterInDescendingSection(height,lastMax);
        return waterTrapped;
    }
    
private:
    int computeTrappedWater(int firstIndex, int secondIndex, vector<int>& height)
    {
        int water= min(height[firstIndex],height[secondIndex])*(secondIndex-firstIndex-1);
        for(int i=firstIndex+1;i<secondIndex;i++) water-=height[i];
        return water;
    }
    int computeWaterInAscendingSection(vector<int>& height)
    {
        int firstHeigthIdx = 0;
        for(int i=1;i<height.size();i++)
        {
            if(height[i]>=height[firstHeigthIdx])
            {
                waterTrapped+=computeTrappedWater(firstHeigthIdx,i,height);
                firstHeigthIdx=i;
            }
        }
        return firstHeigthIdx;
    }
    void computeWaterInDescendingSection(vector<int>& height, int lastIndex)
    {
        int firstHeigthIdx = height.size()-1;
        for(int i=height.size()-2;i>=lastIndex;i--)
        {
            if(height[i]>=height[firstHeigthIdx])
            {
                waterTrapped+=computeTrappedWater(i,firstHeigthIdx,height);
                firstHeigthIdx=i;
            }
        }
    }
    
    int waterTrapped;
};