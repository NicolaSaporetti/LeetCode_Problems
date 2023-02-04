#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxS = *max_element(begin(piles),end(piles));
        int minS = 1;
        int result = maxS;
        while(minS<=maxS)
        {
            int avgS = minS+(maxS-minS)/2;
            if(canEatAllBananas(avgS,piles,h))
            {
                result = avgS;
                maxS=avgS-1;
            }
            else minS = avgS+1;
        }
        return result;
    }
private:
    bool canEatAllBananas(int avgS, vector<int>& piles, int h)
    {
        for(auto& val : piles)
        {
            h-=(val/avgS + ((val%avgS==0)? 0 : 1));
            if(h<0) return false;
        }
        return true;
    }
};