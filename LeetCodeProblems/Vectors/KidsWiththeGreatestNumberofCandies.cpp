#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxValue = *max_element(begin(candies),end(candies));
        for(auto& e : candies)
        {
            if(e+extraCandies>=maxValue) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};