#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int waterTrapped;
    auto computeTrappedWater(int firstIndex, int secondIndex, vector<int>& height)
    {
        int water=0;
        int minHeigth = min(height[firstIndex],height[secondIndex]);
        for(int i=firstIndex+1;i<secondIndex;i++)
        {
            water+=minHeigth-height[i];
        }
        return water;
    }
    auto assertWaterInAscendingSection(vector<int>& height)
    {
        int tempHeigth = height[0];
        int tempHeigthNumber = 0;
        for(auto i=1;i<height.size();i++)
        {
            if(height[i]>=tempHeigth)
            {
                tempHeigth=height[i];
                waterTrapped+=computeTrappedWater(tempHeigthNumber,i,height);
                tempHeigthNumber=i;
            }
        }
        return tempHeigthNumber;
    }
    void assertWaterInDescendingSection(vector<int>& height, int max)
    {
        int tempHeigth = height[height.size()-1];
        int tempHeigthNumber = height.size()-1;
        for(int i=height.size()-2;i>max-1;i--)
        {
            cout<<i<<endl;
            if(height[i]>=tempHeigth)
            {
                tempHeigth=height[i];
                waterTrapped+=computeTrappedWater(i,tempHeigthNumber,height);
                tempHeigthNumber=i;
            }
        }
    } 
public:
    int trap(vector<int>& height) {
        waterTrapped=0;
        if(height.size()>2)
        {
            int lastMax=assertWaterInAscendingSection(height);
            assertWaterInDescendingSection(height,lastMax);
        }
        return waterTrapped;
    }
};