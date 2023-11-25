#include <vector>
#include "..\DD\FenwickTreeOneBasedIndexing.cpp"
using namespace std;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int maxE = *max_element(begin(instructions),end(instructions));
        FenwickTreeOneBasedIndexing ft(maxE);
        int cost = 0;
        int mod = 1e9+7;
        for(auto e : instructions)
        {
            int minl = ft.sum(1,e-1);
            int minr = ft.sum(e+1,maxE);
            //cout<<minl<<" "<<minr<<endl;
            ft.add(e,1);
            cost=(cost+min(minl,minr))%mod;
        }
        return cost;
    }
};