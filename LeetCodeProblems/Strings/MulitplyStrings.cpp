using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string result (num1.size()+num2.size(),'0');
        for(int i=0;i<num1.size();i++)
        {
            int carry = 0;
            for(int j=0;j<num2.size();j++)
            {
                int tot = (num1[i]-'0')*(num2[j]-'0')+carry+result[i+j]-'0';
                carry = tot/10;
                result[i+j] = tot%10+'0';
            }
            if(carry>0) result[i+num2.size()] = carry+'0';
        }
        int i = result.size()-1;
        for(;i>=0;i--)
            if(result[i]!='0')
            {
                result.resize(i+1);
                break;
            }
        if(i==-1) result.resize(1);
        reverse(result.begin(),result.end());
        return result;
    }
};