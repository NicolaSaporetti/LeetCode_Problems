#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res = 0;
        sort(begin(piles),end(piles));
        int sz = piles.size();
        for(int i=0;i<sz/3;i++) res+=(piles[sz-2-i*2]);
        return res;
    }
};