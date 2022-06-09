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
        int count = intResult.size()-1;
        result.resize(intResult.size());
        for(auto i : intResult)
        {
            result[count--]= i+'0';
        }
    }
public:
    string addStrings(string num1, string num2) {
        convertStringToIntVector(num1, number1);
        convertStringToIntVector(num2, number2);
        int carry = 0;
        int sz1 = number1.size();
        int sz2 = number2.size();
        for(int i=1;i<=max(sz1,sz2);i++)
        {
            int num = carry;
            if(sz1-i>=0) num+=number1[sz1-i];
            if(sz2-i>=0) num+=number2[sz2-i];
            intResult.push_back(num%10);
            carry = num/10;
        }
        if(carry>0)
        {
            intResult.push_back(carry);
        }
        convertIntResultToString();
        return result;
    }
};