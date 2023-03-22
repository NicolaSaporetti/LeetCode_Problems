#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int empty=(flowerbed[0]==0)? 1 : 0;
        for(int i=0;i<sz;i++)
        {
            if(flowerbed[i]==1)
            {
                n-=(empty-1)/2;
                empty=0;
            }
            else empty++;
        }
        n-=empty/2;
        empty++;
        return n<=0;
    }
};