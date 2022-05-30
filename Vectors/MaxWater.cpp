#include <iostream>
#include <stdlib.h>
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

int main()
{
    Solution solution;
    vector<int> a = {76,155,15,188,180,154,84,34,187,142,22,5,27,183,111,128,50,58,2,112,179,2,100,111,115,76,134,120,118,103,31,146,58,198,134,38,104,170,25,92,112,199,49,140,135,160,20,185,171,23,98,150,177,198,61,92,26,147,164,144,51,196,42,109,194,177,100,99,99,125,143,12,76,192,152,11,152,124,197,123,147,95,73,124,45,86,168,24,34,133,120,85,81,163,146,75,92,198,126,191};
    cout<<solution.maxArea(a)<<endl;
    return 0;
}