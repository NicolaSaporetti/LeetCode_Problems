#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> step;
    void setupStep(int n)
    {
        step.resize(n/2+1);
        for(int i=0;i<n/2+1;i++)
        {
            step[i]=n-2*i;
        }
    }
    long long int factorial(int highvalue, int low_value)
    {
        long long int result = 1;
        for(int i=low_value;i<=highvalue;i++) result*=i;
        return result;
    }
    long long int factorialSemplified(int highvalue, int low_value, long long int divisor)
    {
        long long int result = 1;
        bool isDivisorApplied = false;
        for(int i=low_value;i<=highvalue;i++)
        {
            result*=i;
            if(!isDivisorApplied)
            {
                if(result%divisor==0)
                {
                    result/=divisor;
                    isDivisorApplied = true;
                }
            }
        }
        return result;
    }
    int computePermutation(int ones, int twos)
    {
        if(ones==0 || twos ==0) return 1;
        else  
        {
            long long int divisor = factorial(min(ones, twos), 1);
            return factorialSemplified(ones+twos, max(ones, twos)+1, divisor);
        }
    }
public:
    int climbStairs(int n) {
        int combinations = 0;
        setupStep(n);
        for(int elem=0;elem<n;elem++)
        {
            combinations+=computePermutation(elem,(n-elem)/2);
        }
        return combinations;
    }
};