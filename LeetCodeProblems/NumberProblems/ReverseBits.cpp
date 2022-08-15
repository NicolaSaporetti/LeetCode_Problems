#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0;i<32;i++)
        {
            result= result<<1;
            result+=n%2;
            n/=2;
        }
        return result;
    }
};