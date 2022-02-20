#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool negative = false;
        long long int solution = 0;
        while(s.size()>i && s[i]==32)
        {
            i++;
        }

        if(s[i]==45) 
        {
            negative=true;
            i++;
        }
        else if(s[i]==43)i++;
        while((s[i]>=48 && s[i]<=57))
        {
            solution*=10;
            solution+=s[i]-48;
            if(negative== false && solution > 2147483647) return 2147483647;
            if(negative== true && solution*-1 < -2147483648) return -2147483648;
            i++;
        }
        if(negative==true) solution*=-1;
        return static_cast<int>(solution);
    }
};

int main()
{
    string s = "   120000000000000";
    Solution solution;
    cout<<solution.myAtoi(s)<<endl;
    return 0;
}