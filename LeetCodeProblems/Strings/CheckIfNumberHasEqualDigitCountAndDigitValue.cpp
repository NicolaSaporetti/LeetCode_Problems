#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        vector<int> digits(10,0);
        for(int i=0;i<num.size();i++)
        {
            digits[num[i]-'0']++;
        }
        for(int i=0;i<num.size();i++)
        {
            if(digits[i]!=num[i]-'0') return false;
        }
        return true;
    }
};