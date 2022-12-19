#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]+=1;
        for(int i=digits.size()-1;i>=1;i--)
        {
            if(digits[i]==10)
            {
                digits[i]=0;
                digits[i-1]++;
            }
        }
        if(digits[0]==10)
        {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};