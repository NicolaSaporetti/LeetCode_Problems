#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        result = -1;
        number = n;
        while(n>0)
        {
            digits.push_back(n%10);
            n/=10;
        }
        int i=1;
        while(i<digits.size() && digits[i-1]<=digits[i]) i++;
        if(i<digits.size())
        {
            replaceNumber()
            sort(digits.begin(), digits.begin()+i, greater<int>());
            result = computeRes(digits);
            if(result>INT_MAX || number==result) result = -1;
        }
        return result;
    }
private:
    long long computeRes(vector<int>& digits)
    {
        long long result = 0;
        for(int i=digits.size()-1;i>=0;i--)
        {
            result*=10;
            result+=digits[i];
        }
        return result;
    }

    void replaceNumber()
    {
        int value = digits[i-1];
        int index = i-1;
        for(int j=0;j<i-1;j++)
            if(digits[j]>digits[i] && digits[j]<value)
            {
                value = digits[j];
                index = j;
            }
        int temp = digits[i];
        digits[i]=digits[index];
        digits[index]=temp;
    }

    vector<int> digits;
    long long result;
    int number;
};