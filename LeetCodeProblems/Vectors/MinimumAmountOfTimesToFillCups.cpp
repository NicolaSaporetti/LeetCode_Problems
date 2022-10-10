#include <vector>
using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int max = *max_element(amount.begin(), amount.end());
        int tot = amount[0]+amount[1]+amount[2];
        if(max>=tot-max) return max;
        else return (tot+1)/2;
    }
};