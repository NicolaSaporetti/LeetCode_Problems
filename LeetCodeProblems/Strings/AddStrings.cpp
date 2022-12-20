#include <vector>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        convertStringToIntVector(num1, number1);
        convertStringToIntVector(num2, number2);
        int carry = 0;
        int sz1 = number1.size();
        int sz2 = number2.size();
        for(int i=0;i<sz1 || i<sz2 || carry;i++)
        {
            int num = carry;
            if(i<sz1) num+=number1[i];
            if(i<sz2) num+=number2[i];
            result.push_back(num%10+'0');
            carry = num/10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
private:
    void convertStringToIntVector(string& num, vector<int>& result)
    {
        for(int i=num.size()-1;i>=0;i--) result.push_back(num[i]-'0');
    }
    
    vector<int> number1;
    vector<int> number2;
    string result;
};