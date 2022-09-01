#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        long long v = 1;
        while(v<=n)
        {
            if(v==n) return v;
            v*=4;
        }
        return false;
    }
};