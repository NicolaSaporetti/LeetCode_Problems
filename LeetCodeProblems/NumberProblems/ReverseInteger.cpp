#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int solution = 0;
        bool isPos = (x>=0)?true:false;
        for(int i=0; x>0 || x<0; i++)
        {
            solution*= 10;
            solution+= x%10;
            x/=10;
        }
        if((isPos==true && solution > 2147483647) ||
           (isPos==false && solution < -2147483648))
        {
            return 0;
        }
        return static_cast<int>(solution);
    }
};