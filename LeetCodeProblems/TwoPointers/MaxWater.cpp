using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r)
        {
            maxWater = max(maxWater,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxWater;
    }
};