#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        int val = 1;
        for(int i=1;i<31;i++)
        {
            val*=2;
            if(val==n) return true;
        }
        return false;
    }
};