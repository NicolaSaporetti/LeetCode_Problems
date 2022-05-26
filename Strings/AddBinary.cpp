#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int value = 0;
        int aI = 0;
        int bI = 0;
        int sza = a.size();
        int szb = b.size();
        int i=0;
        for(i=0;i<min(sza, szb);i++)
        {
            if(a[sza-1-i]=='1') aI = 1;
            else aI = 0;
            if(b[szb-1-i]=='1') bI = 1;
            else bI = 0;
            value = (aI+bI+carry)%2;
            carry = (aI+bI+carry)/2;
            if(value) result.push_back('1');
            else result.push_back('0');
        }
        if(sza>szb)
        {
            for(;i<sza;i++)
            {
                if(a[sza-1-i]=='1') aI = 1;
                else aI = 0;
                value = (aI+carry)%2;
                carry = (aI+carry)/2;
                if(value) result.push_back('1');
                else result.push_back('0');
            }
        }
        else if(szb>sza)
        {
            for(;i<szb;i++)
            {
                if(b[szb-1-i]=='1') bI = 1;
                else bI = 0;
                value = (bI+carry)%2;
                carry = (bI+carry)/2;
                if(value) result.push_back('1');
                else result.push_back('0');
            }
        }
        if(carry) result.push_back('1');
        char temp;
        for(int j=0;j<result.size()/2;j++)
        {
            temp = result[result.size()-1-j];
            result[result.size()-1-j] = result[j];
            result[j] = temp;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    return 0;
}