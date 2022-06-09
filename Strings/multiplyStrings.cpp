#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> number1;
    vector<int> number2;
    vector<int> intResult;
    string result;

    void convertStringToIntVector(string& num, vector<int>& result)
    {
        for(int i=0;i<num.size();i++)
        {
            result.push_back(num[i]-48);
        }
    }
    void convertIntResultToString()
    {
        int zeroToSkip = 0;
        for(;zeroToSkip<intResult.size() ;zeroToSkip++)
        {
            if(intResult[zeroToSkip]!=0) break;
        }
        for(;zeroToSkip<intResult.size();zeroToSkip++)
        {
            result.push_back(intResult[zeroToSkip]+48);
        }
        if(result.empty()) result.push_back('0');
    }
public:
    string multiply(string num1, string num2) {
        convertStringToIntVector(num1, number1);
        convertStringToIntVector(num2, number2);
        intResult.resize(number1.size()+number2.size());
        for(int i=number1.size()-1;i>=0;i--)
        {
            int carry = 0;
            int j = 0;
            for(j=number2.size()-1;j>=0;j--)
            {
                int value = (number1[i]*number2[j]+carry+intResult[i+j+1])%10;
                carry = (number1[i]*number2[j]+carry+intResult[i+j+1])/10;
                intResult[i+j+1] = value;
            }
            if(carry>0)
            {
                intResult[i+j+1] = carry;
            }
        }
        convertIntResultToString();
        return result;
    }
};