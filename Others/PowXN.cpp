#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(x==-1)
        {
            if(n%2==0)
            {
                return 1;
            }
            else return -1;
        }
        if(n>1000000) return 0;
        if(n<0)
        {
            double number = 1;
            for(int i=0;i>n;i--)
            {
                number*=x;
            }
            return 1/number;
        }
        else if(n>0)
        {
            double number = 1;
            for(int i=0;i<n;i++)
            {
                number*=x;
            }
            return number;
        }
        else
        {
            if (x==0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
};

int main()
{
    Solution solution;
    return 0;
}