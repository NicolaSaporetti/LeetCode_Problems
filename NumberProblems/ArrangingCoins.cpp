#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long n1 = n;
        int num = (-1+sqrt(1+8*n1))/2;
        return num;
    }
};