#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& c) {
        sort(begin(c), end(c));
        int max_val = 1;
        for (auto i = 0; i < c.size() && c[i] <= max_val; ++i)
            max_val += c[i];
        return max_val;
    }  
};