#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int total = 1;
        while(n>=3 && n!=4)
        {
            total*=3;
            n-=3;
        }
        while(n>0)
        {
            total*=2;
            n-=2;
        }
        return total;
    }
};