#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool increase_needed = true;
        for(int i=0;i<digits.size();i++)
        {
            if(digits[i]!=9)
            {
                increase_needed = false;
                break;
            }
        }
        if(increase_needed)
        {
            digits.push_back(0);
            for(int i=1;i<digits.size();i++)
            {
                digits[i] = 0;
            }
            digits[0] = 1;
        }
        else
        {
            int carry=1;
            for(int i=digits.size()-1;i>=0;i--)
            {
                int tempcarry = carry;
                carry = (digits[i]+carry)/10;
                digits[i] = (digits[i]+tempcarry)%10;
            }
        }
        return digits;
    }
};