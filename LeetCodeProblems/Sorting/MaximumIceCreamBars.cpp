#include <vector>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int tot = 0;
        int bar = 0;
        for(int i=0;i<costs.size();i++)
        {
            tot+=costs[i];
            if(tot<=coins) bar++;
            else break;
        }
        return bar;
    }
};