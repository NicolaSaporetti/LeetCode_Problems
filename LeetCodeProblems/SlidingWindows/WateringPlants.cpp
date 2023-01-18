#include <vector>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int temp = capacity;
        int res = plants.size();
        for(int i=0;i<plants.size();i++)
        {
            if(temp>=plants[i]) temp-=plants[i];
            else
            {
                res+=(i*2);
                temp = capacity-plants[i];
            }
        }
        return res;
    }
};