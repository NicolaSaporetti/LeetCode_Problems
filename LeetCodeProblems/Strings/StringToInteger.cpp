using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int pos=0;
        long long int solution = 0;
        while(s.size()>pos && s[pos]==' ') pos++;
        bool isNumberNegative = false;
        if(s.size()>pos && s[pos]=='-') 
        {
            isNumberNegative=true;
            pos++;
        }
        else if(s[pos]=='+') pos++;
        while(pos<s.size() && s[pos]>='0' && s[pos]<='9')
        {
            solution*=10;
            solution+=s[pos]-'0';
            if(!isNumberNegative && solution > INT_MAX) return INT_MAX;
            if(isNumberNegative && solution*-1 < INT_MIN) return INT_MIN;
            pos++;
        }
        if(isNumberNegative) solution*=-1;
        return static_cast<int>(solution);
    }
};