#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor == -1)
        {
            return 2147483647;
        }
        else{
            long long int Dividend = static_cast<long long int>(dividend);
            long long int Divisor = static_cast<long long int>(divisor);
            long long int result = 0;
            int shift = 0;
            bool negative = false;
            if((Dividend<0 && Divisor>=0) || (Dividend>=0 && Divisor<0)) negative = true;
            if(Dividend<0) Dividend=0-Dividend;
            if(Divisor<0) Divisor=0-Divisor;
            long long int updatedDivisor=Divisor;
            cout<<"Dividend: "<<Dividend<<endl;
            cout<<"updatedDivisor: "<<updatedDivisor<<endl;
            while(Dividend>=updatedDivisor<<1)
            {
                shift++;
                updatedDivisor=updatedDivisor<<1;
                cout<<"updatedDivisor: "<<updatedDivisor<<endl;
            }
            cout<<"Shift: "<<shift<<endl;
            for(int i=0;i<=shift;i++)
            {
                long long int sum=0;
                int j=0; 
                while(Dividend>=sum+updatedDivisor)
                {
                    j++;
                    sum+=updatedDivisor;
                }
                updatedDivisor = updatedDivisor>>1;
                Dividend-=sum;
                cout<<"Dividend: "<<Dividend<<endl;
                result = result<<1;
                result+= j;
                cout<<"Result: "<<result<<endl;
                sum = 0;
            }
            if (negative == true) result = 0 - result;
            return static_cast<int>(result);
        }
    }
};

int main()
{
    bool testResult = true;
    Solution solution;
    if(solution.divide(1,1)!=1) cout<<"Error"<<endl;
    if(solution.divide(-2147483648,-1)!=2147483647) cout<<"Error"<<endl;
    if(solution.divide(2147483647,1)!=2147483647) cout<<"Error"<<endl;
    if(solution.divide(1,-1)!=-1) cout<<"Error"<<endl;
    return 0;
}