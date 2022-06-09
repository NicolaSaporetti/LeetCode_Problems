#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(;n>0;)
        {
            res+=n%2;
            n/=2;
        }
        return res;
    }
};