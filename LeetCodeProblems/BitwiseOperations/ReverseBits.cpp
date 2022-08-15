#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t value = 0;
        for(int i=0;i<32;i++)
        {
            value*=2;
            value+=n%2;
            n/=2;
        }
        return value;
    }
};