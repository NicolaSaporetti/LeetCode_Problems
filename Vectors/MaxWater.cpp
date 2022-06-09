#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int j = height.size()-1;
        for(int i=0; i<height.size()-1 && maxWater<(j-i)*10000; i++)
        {
            for(j=height.size()-1; j>i && maxWater<(j-i)*10000; j--)
            {
                int localWater = min(height[i],height[j])*(j-i);
                if(localWater>maxWater)
                {
                    maxWater = localWater;
                }
            }
            j = height.size()-1;
        }
        return maxWater;
    }
};